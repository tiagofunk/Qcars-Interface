echo "python pymake.py build"
python pymake.py build

echo "./src/memplas 1 1 1 ../Instances/Angola12n.pcar --strategy mpr --sizePopulation 10 --elite 0.4 --limitIterations 500 --sizePlasmideo 0.5 --cross 0.85 --selectionStrategy a --intermediaryStrategy stef"
./src/memplas 1 1 1 ../Instances/Angola12n.pcar --strategy mpr --sizePopulation 10 --elite 0.4 --limitIterations 500 --sizePlasmideo 0.5 --cross 0.85 --selectionStrategy a --intermediaryStrategy stef