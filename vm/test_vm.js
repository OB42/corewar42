var async = require("async");
var c = ['ultima.cor',
  'slider2.cor',
  'Misaka_Mikoto.cor',
  'champ.cor',
  '_.cor',
  'valid.cor'];
var fs = require('fs');
const {exec} = require('child_process');
var t = [];
c.forEach(y => t.push([y, y, t.length]));
if (process.argv.length == 4 && !isNaN(process.argv[2] * 1) && !isNaN(process.argv[3] * 1))
	t = t.slice(process.argv[2] * 1, process.argv[3] * 1);
path = require("path");
var F = 0;
var P = 0;
var show_msg = (arr) => {
	console.log('_____________________________________________________________________________________________________________________________');
	arr.forEach(x => console.log(x));
}
var fail = (arr, filename, id) =>
{
	show_msg(arr);
	console.log(`Test nº ${id}:	\x1b[31mFAILING ${F++ +1}/${t.length} tests\x1b[0m`, filename);
};
var pass = (arr, filename, id) =>
{
	show_msg(arr);
	console.log(`Test nº ${id}:	\x1b[32mPASSING ${P++ +1}/${t.length} tests\x1b[0m`, filename);
};
var test = (files, err, stdout, stderr, callback) => {
	var zaz = fs.readFileSync(`zaz/${files[0]}_${files[1]}`).toString();
	var z = 0;
	var vburidar = stdout.split('\n');
	var msg_arr = [`./corewar ../asm/mine/${files[0]} ../asm/mine/${files[1]}`];
	if (!zaz.length)
	{
		msg_arr.push("Zaz vm probably returned an error");
	}
	else
	{
		zaz = zaz.split('\n');
		var first_diff = -1;
		var n_diff = 0;
		var difo = {}
		for (var i = 0; i < zaz.length && i < vburidar.length; i++)
		{
			if (zaz[i] != vburidar[i])
			{
				zaz[i] = `\x1b[31m${zaz[i]}\x1b[0m`;
				vburidar[i] = `\x1b[31m${vburidar[i]}\x1b[0m`;
			}
		}
		for (var i = 0; i < zaz.length && i < vburidar.length; i++)
		{
			if (zaz[i] != vburidar[i])
			{
				n_diff++;
				if (first_diff == -1)
				{
					msg_arr.push(`First diff at line ${i}:`);
					msg_arr.push(`Zaz:`);
					msg_arr.push('_______________________________');
					msg_arr = msg_arr.concat(zaz.slice(i - 2, i + 3));
					msg_arr.push('_______________________________');
					msg_arr.push(`Us:`);
					msg_arr.push('_______________________________');
					msg_arr = msg_arr.concat(vburidar.slice(i - 2, i + 3));
					msg_arr.push('_______________________________');
					first_diff = i;
				}
			}
		}
		if (n_diff)
			msg_arr.push(`${n_diff} different lines(before any potential crash)`);
		if (zaz.length < vburidar.length)
			msg_arr.push(`${vburidar.length - zaz.length} extraneous lines`);
	}
	if (stderr.length)
	{
		fs.writeFileSync(`errors/${files[0]}_${files[1]}.error`, stderr);
		msg_arr.push(`\x1b[31mAn error was detected and stored in errors/${files[0]}_${files[1]}.error\x1b[0m`);
	}
	else if (vburidar.length < zaz.length)
		msg_arr.push(`${zaz.length - vburidar.length} missing lines`);
	if ((n_diff && !z) || stderr.length)
		fail(msg_arr, `${files[0]} vs ${files[1]}`, files[2]);
	else
		pass(msg_arr, `${files[0]} vs ${files[1]}`, files[2]);
	callback();
};
exec(`rm errors/*; make -C ../asm; ${c.filter(x => !(fs.existsSync('../asm/mine/' +x))).map(x => `../asm/asm ../asm/mine/${x.replace('.cor', '.s')}`).join(';')}`, () => {
	exec(`make re`, (err, stdout, stderr) => {
		if (stderr.length)
		{
			console.log(stderr);
			if (!(stderr.match("creating archive")))
				return (0);
		}
		async.eachLimit(t, 4, function(files, callback) {
			exec(`./corewar ../asm/mine/${files[0]} ../asm/mine/${files[1]}`, {maxBuffer: 1024 * 1024 * 64},
			(err, stdout, stderr) => {
			
				test(files, err, stdout, stderr, callback);
			});
		}, function(err) {
		});
	});
});
