function get_cate(id, page, callback) {
	return $.get('https://pinyin.sogou.com/dict/cate/index/' + id + '/default/' + page, {}, callback);
}

function gen_filename(url) {
	url = url.replace(/https?:\/\//, '');
	if ('/' === url[url.length - 1])
		url = url.substring(0, url.length - 1);
	let name = url.match(/\/[^\/]+$/);
	if (!name)
		name = url;
	else
		name = name[0];
	if (name.length > 256)
		url = url.substring(0, url.length - name.length) + name.substring(0, 256);
	return url;
}

function correct_name(name) {
	return name.replace(/[ \\\/:*?\"<>|]/g, '_');
}

id = 419;
pages = [];

function _loop() {
	let page = 1;
	let max_page = 1;
	pages[id] = [];

	function __loop() {
		get_cate(id, page, function(data) {
			let info = data.match(/“(.*)”分类下共有(\d+)个词库/);
			let cate = info[1];
			let total = +info[2];
			let _max_page = data.match(/<a href="\/dict\/cate\/index\/\d+\/default\/(\d+)">\1<\/a>/g);
			if (_max_page) {
				_max_page = _max_page.pop();
				_max_page = +_max_page.match(/default\/(\d+)/)[1];
				if (max_page < _max_page)
					max_page = _max_page;
			}
			if (!cate && !total)
				return console.log(id, page, 'End of download!');
			pages[id].push(data);
			++page;
			if (page > max_page) {
				++id;
				return setTimeout(_loop, 10);
			} else {
				return setTimeout(__loop, 10);
			}
		});
	}
	__loop();
}
_loop();


// fs.writeFileSync('pages.json', JSON.stringify(pages));

// pages = JSON.parse(fs.readFileSync('pages.json'));

dicts = [];

pages.forEach(function(ele, index) {
	ele.forEach(function(e, i) {
		let info = e.match(/“(.*)”分类下共有(\d+)个词库/);
		let cate = info[1];
		let total = +info[2];
		let _dicts = e.match(/<div class="detail_title"><a href='\/dict\/detail\/index\/(\d+)'>(.+)<\/a><\/div>\r\n\s+<\/div>\r\n\s+<div class="dict_detail_show">\r\n\s+<div class="dict_detail_content">\r\n\s+<div class="show_title">词条样例：<\/div>\r\n\s+<div class="show_content">(.*)<\/div>\r\n\s+<div class="show_title">下载次数：<\/div>\r\n\s+<div class="show_content">(\d+)<\/div>\r\n\s+<div class="show_title">更新时间：<\/div>\r\n\s+<div class="show_content">(.+)<\/div>                            \r\n\s+<\/div>\r\n\s+<div class="dict_dl_btn"><a href="http:\/\/download.pinyin.sogou.com\/dict\/download_cell.php\?id=(\d+)&name=(.+)"><\/a><\/div>/g);
		if (_dicts)
			_dicts.forEach(function(d, i) {
				d = d.match(/<div class="detail_title"><a href='\/dict\/detail\/index\/(\d+)'>(.+)<\/a><\/div>\r\n\s+<\/div>\r\n\s+<div class="dict_detail_show">\r\n\s+<div class="dict_detail_content">\r\n\s+<div class="show_title">词条样例：<\/div>\r\n\s+<div class="show_content">(.*)<\/div>\r\n\s+<div class="show_title">下载次数：<\/div>\r\n\s+<div class="show_content">(\d+)<\/div>\r\n\s+<div class="show_title">更新时间：<\/div>\r\n\s+<div class="show_content">(.+)<\/div>                            \r\n\s+<\/div>\r\n\s+<div class="dict_dl_btn"><a href="http:\/\/download.pinyin.sogou.com\/dict\/download_cell.php\?id=(\d+)&name=(.+)"><\/a><\/div>/);
				dicts.push({
					cate: cate,
					name: d[2],
					example: d[3],
					downloads: +d[4],
					update_time: d[5],
					id: +d[6],
					url_name: d[7],
				});
			});
	});
});

// fs.writeFileSync('dicts.json', JSON.stringify(dicts));

// dicts = JSON.parse(fs.readFileSync('dicts.json'));


dicts.sort((a, b) => a.downloads - b.downloads);
dicts.reverse();
// fs.writeFileSync('dicts_sorted.json', JSON.stringify(dicts));

download = '';

dicts.forEach(function(e, i) {
	download += 'http://download.pinyin.sogou.com/dict/download_cell.php?id=' + e.id + '&name=' + e.url_name + '\n' +
		'\tout=' + correct_name(e.cate + '_' + e.name) + '.scel\n';
});

fs.writeFileSync('download.txt', download);


_names = [];
dicts.forEach(function(e, i) {
	_names.push(correct_name(e.cate + '_' + e.name) + '.scel');
});

names = '';
Array.from(new Set(_names)).slice(0, 1000).forEach(function(e, i) {
	names += e + '\n';
});

fs.writeFileSync('hot.txt', names);


temp = fs.readFileSync('temp.txt', {
	encoding: 'utf8'
}).split('\n');

_names.forEach(function(element, index) {
	if (!temp.includes(element))
		console.log(element);
});

temp.filter(function(argument) {
	return -1 === argument.indexOf('.1.scel') && -1 === argument.indexOf('.scel.aria2');
});