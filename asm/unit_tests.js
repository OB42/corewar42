const exec = require('child_process').execSync;
path = require("path");
try {
	exec(`rm vm_champs/*.cor`);
} catch (e) {
	console.log("nothing to del");
}
try {
	exec(`rm mine/*.cor`);
} catch (e) {
	console.log("nothing to del");
}
exec(`make`);
(fs = require('fs'))
.readdirSync('./mine')
.forEach((filename, i) => {
	var b = path.resolve(`mine/${filename}`);
	var a = path.resolve(`vm_champs/${filename}`);
	var bx = path.resolve(`mine/${filename.replace('.s', '.cor')}`);
	var ax = path.resolve(`vm_champs/${filename.replace('.s', '.cor')}`);
	console.log('______________________')
	try {
		exec(`./asm ${a}`);
	} catch (e) {
//		console.log(e.stderr.toString());
	}
	try {
		exec(`./rasm ${b}`);
	} catch (e) {
		console.log("error in vm_champs:", e.stdout.toString());
	}
	try {
		if ((fs.existsSync(ax) && fs.existsSync(bx)))
		{
			exec(`diff ${ax} ${bx}`);
			console.log(`${ax} and ${bx} are identical.`)
		}
		if ((fs.existsSync(ax) && fs.existsSync(bx)) || (!fs.existsSync(ax) && !fs.existsSync(bx)))
			console.log('\x1b[32mPASSING\x1b[0m', filename , `Both files were ${(fs.existsSync(ax) && fs.existsSync(bx)) ? '' : 'NOT '}created`);
		else
		{
			try {
				exec(`./rcorewar ${bx}`);
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
	}
});
