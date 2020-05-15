from os import listdir
from os.path import isfile, join
import subprocess

program = "./QcarsInterface.exe"
mypath = "Instances/"
instances = [join(mypath, f) for f in listdir(mypath) if isfile(join(mypath, f))]

# ./QcarsInterface.exe 1 2 3 Instances/AfricaSul11n.pcar --strategy mpr --sizePopulation 10 --elite 0.40 --limitIterations 10 --sizePlasmideo 0.50 --cross 0.85 --selectionStrategy a --intermediaryStrategy stef

arguments=[program, "1", "2", "3", "", "--strategy", "mpr", "--sizePopulation", "10", "--elite", "0.40", "--limitIterations", "10", "--sizePlasmideo", "0.50", "--cross", "0.85", "--selectionStrategy", "a", "--intermediaryStrategy", "stef"]

arquivo = open('log.txt', 'w')

for i in range( 30 ):
    for j in instances:
        arguments[4] = j
        py2output = subprocess.check_output( arguments )
        arquivo.write( j.replace("Instances/","").replace(".pcar","") )
        arquivo.write( "," )
        arquivo.write( str( py2output ).replace("b","").replace("\'","") )
        arquivo.write( "\n" )
    print( ">>>>>>>>> ", i )
    
arquivo.close()