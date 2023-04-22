#!/bin/bash
#SBATCH --job-name=summaSimple
#SBATCH -n 4
#SBATCH --output=output_summaSimple.txt
#SBATCH --error=error_summaSimple.txt
hostname
gcc -fopenmp omp_summaSimple.c -o summaSimple
./summaSimple
