const {exec} = require('child_process');

path = require("path");
exec('rm vm_champs/*.cor;rm mine/*.cor;rm temp_test;make re', () => {
	var P = 0;
	var F = 0;
	var arr = (fs = require('fs'))
	.readdirSync('./mine');
	arr.forEach((filename, i) => {
		var a = path.resolve(`mine/${filename}`).slice(0, -2);
		var b = path.resolve(`vm_champs/${filename}`).slice(0, -2);
		exec(`./asm ${a}.s`, (err, stdout, stderr) => {
			exec(`./rasm ${b}.s`, (berr, bstdout, bstderr) => {
				var ar = stdout + stderr;
				var br = bstdout + bstderr;
				if (ar.match("Writing output") && br.match("Writing output"))
				{
						exec(`diff ${a}.cor ${b}.cor`, (err, stdout, stderr) => {
							if (!(stdout.length))
								pass(filename, "Both files were created and are identical.", "");
							else {
								exec(`hexdump ${a}.cor > temp_hex_mine; hexdump ${b}.cor > temp_hex_vm_champs; diff temp_hex_mine temp_hex_vm_champs`, (err, stdout, stderr) => {
									fail(filename, "Different files", (err + stderr + stdout).slice(0, 2048));
								});
							}
						});
				}
				else if (!(ar.match("Writing output")) && !(br.match("Writing output")) && !(ar.match(/fault|bus|free/i)))
					pass(filename, "Both ASMs returned an error", "Mine:", ar, "vm_champs:", br);
				else if (ar.match(/fault|bus|free/i))
					fail(filename, "My ASM probably crashed", ar);
				else if (!(ar.match("Writing output")) && (br.match("Writing output")))
				{
					exec(`./rcorewar ${b}.cor`, (err, stdout, stderr) => {
						if ((stderr + stdout).match(/error/i))
							pass(filename, "Corewar and my ASM both returned an error.", stdout + stderr);
						else
							fail(filename, "My ASM returned an error when compiling a valid file.", ar + stdout + stderr);
					})
				}
				else
					fail(filename, "My corewar compiled an unvalid .s file.", bstdout + bstderr);
			});
		});
	});
	var show_msg = (title, text) => {
		console.log('_________________________');
		console.log(title);
		console.log(text);
	}
	var fail = (filename, title, text) =>
	{
		show_msg(title, text);
		console.log(`\x1b[31mFAILING ${F++ +1}/${arr.length} tests\x1b[0m`, filename);
		if (P + F == arr.length)
			exec('rm */*.cor;rm temp_hex_mine; rm temp_hex_vm_champs', () => {});
	}
	var pass = (filename, title, text) =>
	{
		show_msg(title, text);
		console.log(`\x1b[32mPASSING ${P++ +1}/${arr.length} tests\x1b[0m`, filename);
		if (P + F == arr.length)
			exec('rm */*.cor;rm temp_hex_mine; rm temp_hex_vm_champs', () => {});
	}
});
