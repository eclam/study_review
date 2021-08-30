import os
import re
import shutil
import datetime
from pathlib import *

## Strictly grab all subdirs
def grabDirectories(filePath = os.getcwd()):
    return [x[0] for x in os.walk(os.path.realpath(filePath))]

## Strictly grab all files in all subdirs
def grabAllFilePaths(filePath = os.getcwd()):
    return [str(path) for path in Path(filePath).glob('**/*') if path.is_file()]

def filterBy(filterCondition, listDir):
    listDir = [i for i in listDir if re.search(r"\/{}$".format(filterCondition), i)]

    ## Dealing with edge case if filterCondition == "java"
    try:
        listDir.remove(os.getcwd())
    except:
        pass
    return listDir

def deleteDir(listDir):
    for folder in listDir:
        shutil.rmtree(folder)

def deleteFile(listDir):
    for filePath in listDir:
        os.remove(filePath)

def getParentDir(path):
    return os.path.abspath(os.path.join(path, os.pardir))

def moveFiles(listDir, filterCondition = 'src/main/java', filePath = os.getcwd()):
    listDir = ([str(path) for path in Path(filePath).glob(
        '**/{}/*'.format(filterCondition)) if path.is_file()]).sort()

    try:
        for src in listDir:
            filename = os.path.basename(src)
            dest = getParentDir(getParentDir(getParentDir(getParentDir(src))))
            if os.path.isfile(os.path.join(dest, filename)):
                filename = "{}_{}".format(filename,
                    datetime.datetime.now().strftime("%d%b%y%H%M%S"))
                dest = os.path.join(dest, filename)
            else:
                dest = os.path.join(dest, filename)

            try:
                # print("Moved Successfully \n\t src: {} \n\t dest: {}".format(src, dest))
                shutil.move(src, dest)
            except:
                # print("Failed to move - \n\t src: {} \n\t dest: {}".format(src,dest))
                pass
    except:
        # print("No files found. Probably used script already.")
        pass


if __name__ == '__main__':
    ## Delete not needed directories
    deleteDir(filterBy("target", grabDirectories()))
    deleteDir(filterBy("test", grabDirectories()))

    ## Delete not needed files
    deleteFile(filterBy('.tmcproject.json', grabAllFilePaths()))
    deleteFile(filterBy('.tmcproject.yml', grabAllFilePaths()))
    deleteFile(filterBy('.checkstyle.xml', grabAllFilePaths()))
    deleteFile(filterBy('pom.xml', grabAllFilePaths()))

    ## Move all my work to 2 folders up
    moveFiles(grabAllFilePaths())

    ## Delete old directories
    deleteDir(filterBy("src", grabDirectories()))

    ## DEBUG
    # listDir = grabAllFilePaths()
    # for i in listDir:
    #     print(i)

