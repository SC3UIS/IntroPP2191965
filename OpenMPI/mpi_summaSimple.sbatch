#!/bin/bash
#SBATCH --job-name=mpi_summaSimple
#SBATCH -n 12
#SBATCH --output=output_mpi_summaSimple.txt
#SBATCH --error=error_mpi_summaSimple.txt
module purge
module load devtools/mpi/openmpi/3.1.4
hostname
mpicc -Wall mpi_summaSimple.c -o output_mpi_summaSimple
mpirun ./output_mpi_summaSimple 12000
