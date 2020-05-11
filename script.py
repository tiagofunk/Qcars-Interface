from os import listdir
from os.path import isfile, join
import subprocess

program = join("./Project/Debug/", "QcarsInterface.exe")
mypath = "Instances/"
instances = [join(mypath, f) for f in listdir(mypath) if isfile(join(mypath, f))]

arguments=[program, "1", "2", "3", "", "--strategy", "mpr", "--sizePopulation", "10", "--elite", "0.40", "--limitIterations", "10", "--sizePlasmideo", "0.50", "--cross", "0.85", "--selectionStrategy", "a", "--intermediaryStrategy", "stef"]

arguments[4] = instances[0]
print( arguments )

py2output = subprocess.check_output(arguments)
#print('py2 said:', py2output)

#for i in range( 30 ):
#    for j in instances:
#        print( j )
#    print( ">>>>>>>>>" )