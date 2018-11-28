#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import hashlib
import shutil

path = '/Users/felix/Documents/2d/restapp/RestApp/'
resultPath = '/Users/felix/Documents/2d/RES/'

def copyResource(path):
    files = []
    for parent, dirnames, filenames in os.walk(path):
        for dirName in dirnames:
            if dirName == 'Resources':
                resourcePath = os.path.join(parent, dirName)
                hashName = hashlib.sha224(resourcePath.encode('utf-8')).hexdigest()
                shutil.copytree(resourcePath, resultPath+hashName)
                files.append(resourcePath)
                print(resourcePath)
    return files

def main():
    files = copyResource(path)
    print('Done')

if __name__ == "__main__":
    main()