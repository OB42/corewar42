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
						console.log(stdout + stderr)
						if ((stderr + stdout).match(/error/i))
						{
							console.log("Corewar and my ASM both returned an error.")
							pass(filename, i);
						}
						else {
							console.log("My ASM returned an error when compiling a valid file.")
							console.log(ar);
							fail(filename, i);
						}
					})
				}
				else {
					console.log("THIS PROBABLY WONT HAPPEN(too lazy to handle this case)")
				}
			});
		});
	});
	var fail = (filename) =>
	{
		console.log(`\x1b[31mFAILING ${F++ +1}/${arr.length} tests\x1b[0m`, filename);
	}
	var pass = (filename) =>
	{
		console.log(`\x1b[32mPASSING ${P++ +1}/${arr.length} tests\x1b[0m`, filename);
	}
})

/*	try {
		exec(`./rasm ${b}.s >> temp_test 2>&1`);
	} catch (e) {
		exec(`./rasm ${b}.s >> temp_test 2>&1`);
	} finally {
		if ((fs.existsSync(a + '.cor') && fs.existsSync(b + '.cor')))
		{
//			exec(`diff ${ax} ${bx}`);
			console.log(`good`)
		}
		else {
			console.log(`bad`)
		}

	}*/

/*		if ((fs.existsSync(ax) && fs.existsSync(bx)) || (!fs.existsSync(ax) && !fs.existsSync(bx)))
			console.log('\x1b[32mPASSING\x1b[0m', filename , `Both files were ${(fs.existsSync(ax) && fs.existsSync(bx)) ? '' : 'NOT '}created`);
		else
		{
			try {
				console.log("COREWAR", filename)
				exec(`./rcorewar ${ax}`);
				console.log('\x1b[31mFAILING\x1b[0m', filename);

			} catch (e) {
				console.log("error in corewar:", e.stdout.toString());
				console.log('\x1b[32mPASSING\x1b[0m', filename);
			}
		}
	} catch (e) {
		exec(`hexdump ${bx} > temp_hex_mine`);
		exec(`hexdump ${ax} > temp_hex_vm_champs`);
		try {
			exec(`diff temp_hex_mine temp_vm_champs`);
		}
		catch (e){
			console.log(e.stdout.toString());
			console.log('\x1b[31mDIFFER\x1b[0m', filename);
		}
	}*/
