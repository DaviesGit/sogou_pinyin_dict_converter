function correct_name(name) {
	return name.replace(/[ \\\/:*?\"<>|]/g, '_');
}

function arraysAreIdentical(arr1, arr2) {
	if (arr1.length !== arr2.length) return false;
	for (var i = 0, len = arr1.length; i < len; i++) {
		if (arr1[i] !== arr2[i]) {
			return false;
		}
	}
	return true;
}

function find_pinyin(pinyin, p, word) {
	for (let i = 0, end = pinyin.length; i < end; ++i) {
		if (word === pinyin[i][0] && arraysAreIdentical(p, pinyin[i][3]))
			return i;
	}
	return -1;
}


_pinyin = fs.readFileSync('libgooglepinyin-0.1.2/data/_rawdict_utf16_65105_freq.txt', {
	encoding: 'utf16le'
});
if (_pinyin[0] !== '\ufeff')
	throw ('File format error!');
_pinyin = _pinyin.substring(1, _pinyin.length);
_pinyin = _pinyin.split('\n');
_pinyin.pop();
pinyin = _pinyin.map(function(e) {
	e = e.split(' ');
	return [e[0], +e[1], +e[2], e.slice(3)];
});

pinyin_dict = {};
pinyin.forEach(function(e, index) {
	pinyin_dict[e[3].join(',') + e[0]] = e;
});

base_dir = 'json/';
files = fs.readdirSync(base_dir);
files.forEach(function(ele, index) {
	let _pinyin = JSON.parse(fs.readFileSync(path.join(base_dir, ele), {
		encoding: 'utf8'
	}));
	_pinyin.forEach(function(e, i) {
		let ii = pinyin_dict[e.pinyin.join(',') + e.word];
		let frequency=e.frequency;
		if(frequency<0){
			frequency=50-Math.log2(-frequency);
		}else{
			if(frequency>50)
			frequency=50+Math.log2(frequency);
		}
		if (!ii) {
			pinyin_dict[e.pinyin.join(',') + e.word] = [e.word, frequency, 0, e.pinyin];
		} else {
			ii[1] = Math.max(ii[1], frequency);
		}
	});
	console.log('Flie: ', ele, 'finished!')
});

pinyin = [];
for (let prop in pinyin_dict) {
	pinyin.push(pinyin_dict[prop]);
}

// fs.writeFileSync('rawdict_utf16_65105_freq.json', JSON.stringify(pinyin));

// pinyin = JSON.parse(fs.readFileSync('rawdict_utf16_65105_freq.json', {encoding: 'utf8'}));

pinyin = pinyin.filter((e) => {
	return e[0]&&e[3].length&&e[3].length===e[0].length&&e[0].length<=4;
});
pinyin.forEach((e) => {
	if (!e[0]) console.log(e);
	// if (!e[1]) console.log(e);
	if (!e[3].length) console.log(e);
	if (-1!==e[0].indexOf(/\s/)) console.log(e);
	if (e[3].length!==e[0].length) console.log(e);
});

rawdict_utf16_65105_freq = '';

pinyin.forEach(function(e, index) {
	rawdict_utf16_65105_freq += e.slice(0, 3).join(' ') + ' ' + e[3].join(' ') + '\n';
});

// fs.writeFileSync('rawdict_utf16_65105_freq.txt', Buffer.from('\ufeff'+rawdict_utf16_65105_freq, 'utf16le'));

word = new Set();
let _word = fs.readFileSync('libgooglepinyin-0.1.2/data/valid_utf16.txt', {
	encoding: 'utf16le'
});
if (_word[0] !== '\ufeff')
	throw ('File format error!');
_word = _word.substring(1, _word.length);
for (let w of _word)
	word.add(w);
pinyin.forEach(function(e, index) {
	for (let w of e[0])
		word.add(w);
});
word = Array.from(word).join('');
// fs.writeFileSync('valid_utf16.txt',  Buffer.from('\ufeff'+word, 'utf16le'));

//