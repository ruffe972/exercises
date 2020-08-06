#!/usr/bin/env python3
from pathlib import Path
import sys
import os

LABS_COUNT = 5

HTML_PREFIX = '''
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <link rel="stylesheet" href="style.css" type="text/css">
    </head>
    <body>
        <a href="menu.html">Назад</a>'''

HTML_SUFFIX = ('<a href="menu.html">Назад</a>'
               '</body>'
               '</html>')

for i in range(1, LABS_COUNT + 1):
    html_file = 'site/lab_0{0}.html'.format(i)
    command = 'cmark lab_0{0}.md > {1}'.format(i, html_file)
    os.system(command)
    with open(html_file, 'r') as file:
        old_content = file.read()
    with open(html_file, 'w') as file:
        file.write(HTML_PREFIX + old_content + HTML_SUFFIX)
print('Done.')

