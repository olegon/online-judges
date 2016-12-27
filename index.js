/*
Todos os diretórios que possuirem os arquivos desc.txt e main.{c,cpp} serão manipulados.
Como resultado, o arquivo com main.{c,cpp} receberá o conteúdo de desc.txt como comentário no começo do código
e o arquivo desc.txt será excluído.
*/

const fs = require('fs');
const path = require('path');

function checar(caminho) {
    fs.stat(caminho, (err, stats) => {
        if (err) throw new Error(err);

        if (stats.isDirectory()) {
            lerDiretorio(caminho);
        }
    });
}

function lerDiretorio(caminho) {
    fs.readdir(caminho, (err, arquivos) => {
        if (err) throw new Error(err);

        if ((arquivos.includes('main.cpp') || arquivos.includes('main.c')) && arquivos.includes('desc.txt')) {
            manipularCodigoFonte(caminho, arquivos.includes('main.cpp') ? 'main.cpp' : 'main.c');
        }
        else {
            for (let nomeDoArquivo of arquivos) {
                if (nomeDoArquivo == '.git') continue;
                checar(path.join(caminho, nomeDoArquivo));
            }
        }

    });
}

function manipularCodigoFonte(caminho, nomeDoArquivo) {
    fs.readFile(path.join(caminho, 'desc.txt'), 'utf8', (err, desc) => {
        if (err) throw new Error(err);

        fs.readFile(path.join(caminho, nomeDoArquivo), 'utf8', (err, source) => {
            if (err) throw new Error(err);

            fs.writeFile(path.join(caminho, nomeDoArquivo), `/*\n${desc}*/\n\n${source}`, 'utf8', (err) => {
                if (err) throw new Error(err);
            });

            fs.unlink(path.join(caminho, 'desc.txt'), (err) => {
                if (err) throw new Error(err);
            });
        });
    });
}

checar(__dirname);
