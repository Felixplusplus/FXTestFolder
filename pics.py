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
        for f in filenames:
            if len(f.split('.',1)) > 1 and (f.split('.',1)[1] == 'png' or f.split('.',1)[1] == 'jpg'):
                resourcePath = os.path.join(parent, f)
                shutil.copy2(resourcePath, resultPath)
                print(resourcePath)
    return files

def main():
    files = copyResource(path)
    print('Done')

if __name__ == "__main__":
    main()