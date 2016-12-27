const fs = require('fs');
const path = require('path');

function check(pathname) {
    fs.stat(pathname, function (err, data) {
        if (err) throw new Error(err);

        if (data.isDirectory()) {
            readDirectory(pathname);
        }
    });
}

function readDirectory(pathname) {
    fs.readdir(pathname, function (err, data) {
        if (err) throw new Error(err);

        if ((data.includes('main.cpp') || data.includes('main.c')) && data.includes('desc.txt')) {
            manipulate(pathname, data.includes('main.cpp') ? 'main.cpp' : 'main.c');
        }
        else {
            for (let name of data) {
                check(path.join(pathname, name));
            }
        }

    });
}

function manipulate(pathname, sourcename) {
    fs.readFile(path.join(pathname, 'desc.txt'), 'utf8', function (err, desc) {
        if (err) throw new Error(err);

        fs.readFile(path.join(pathname, sourcename), 'utf8', function (err, source) {
            if (err) throw new Error(err);

            fs.writeFile(path.join(pathname, sourcename), `/*\n${desc}*/\n\n${source}`, 'utf8', function (err, data) {
                if (err) throw new Error(err);
            });

            fs.unlink(path.join(pathname, 'desc.txt'), function (err, data) {
                if (err) throw new Error(err);
            });
        });
    });
}

check(__dirname);
