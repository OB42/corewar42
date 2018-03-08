const {exec} = require('child_process');

path = require("path");
exec('rm vm_champs/*.cor;rm mine/*.cor;rm temp_test;make', () => {
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
							{
								console.log('_________________________');
								console.log("Both files were created and are identical.");
								pass(filename, i);
							}
							else {
								exec(`hexdump ${a}.cor > temp_hex_mine; hexdump ${b}.cor > temp_hex_vm_champs; diff temp_hex_mine temp_hex_vm_champs`, (err, stdout, stderr) => {
									console.log('_________________________');
									console.log(err + stderr + stdout)
									fail(filename, i);
								});
							}
						});
				}
				else if (!(ar.match("Writing output")) && !(br.match("Writing output")) && !(ar.match(/fault|bus|free/i)))
				{
					console.log('_________________________');
					console.log("Both ASMs returned an error");
					console.log("Mine:", ar, "vm_champs:", br);
					pass(filename, i);
				}
				else if (ar.match(/fault|bus|free/i))
				{
					console.log('_________________________');
					console.log("My ASM probably crashed", ar)
					fail(filename, i);
				}
				else if (!(ar.match("Writing output")) && (br.match("Writing output")))
				{
					exec(`./rcorewar ${b}.cor`, (err, stdout, stderr) => {
						console.log('_________________________');
						if ((stderr + stdout).match(/error/i))
						{
							console.log("Corewar and my ASM both returned an error.")
							console.log(stdout + stderr)
							pass(filename, i);
						}
						else {
							console.log("My ASM returned an error when compiling a valid file.")
							console.log(ar);
							console.log(stdout + stderr)
							fail(filename, i);
						}
					})
				}
				else {
					console.log("THIS PROBABLY SHOULDN'T HAPPEN")
				}
			});
		});
	});
	var fail = (filename) =>
	{
		console.log(`\x1b[31mFAILING ${F++ +1}/${arr.length} tests\x1b[0m`, filename);
		if (P + F == arr.length)
			exec('rm */*.cor', () => {});
	}
	var pass = (filename) =>
	{
		console.log(`\x1b[32mPASSING ${P++ +1}/${arr.length} tests\x1b[0m`, filename);
		if (P + F == arr.length)
			exec('rm */*.cor', () => {});
	}
});
