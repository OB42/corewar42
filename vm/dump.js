var champs = [process.argv[2], process.argv[3]];
var dump = process.argv[4] * 1;
var all = process.argv[5] * 1;
fs = require("fs")
const {exec} = require('child_process');
//console.log(champs, dump, all);
//sync(`make; ../asm/rcorewar -d ${dump} ${champs.join(' ')} > temp_zaz; ./corewar -dump ${dump} ${champs.join(' ')} > temp_team && diff temp_zaz temp_team`);

exec(`make;make -C ../asm; ${champs.map(x => `../asm/asm ../asm/mine/${x.replace('.cor', '.s')}`).join('; ')}`, (err, stdout, stderr) => {
	if (stderr || err)
		console.log(stderr, err);
	exec(`../asm/rcorewar -v 31 -d ${dump} ../asm/mine/${champs.join(' ../asm/mine/')} > temp_zaz`, (err, stdout, stderr) => {
		if (stderr || err)
			console.log(stderr, err);
		exec(`./corewar -dump ${dump} ../asm/mine/${champs.join(' ../asm/mine/')} > temp_team`, (err, stdout, stderr) => {
			if (stderr || err)
				console.log(stderr, err);
			exec(`diff temp_zaz temp_team`, (err, stdout, stderr) => {
				console.log(stdout);
			})
		})
	})
})
