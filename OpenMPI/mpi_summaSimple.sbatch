#!/bin/bash
#SBATCH --job-name=mpi_summaSimple
#SBATCH -n 12
#SBATCH --output=output_mpi_summaSimple.txt
#SBATCH --error=error_mpi_summaSimple.txt
hostname
mpicc -Wall mpi_summaSimple.c -o output_mpi_summaSimple
mpirun ./summaSimple 12000
