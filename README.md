# Loop Unrolling Optimization

This repository contains the source code and documentation for the study of internal loop unrolling with optimization of reduction operations. The goal of this project is to assess the impact of loop unrolling on the optimization of reduction operations in terms of computational performance and cache usage.

## Description

Loop unrolling is a code optimization technique aimed at reducing the runtime of loops by decreasing the number of iterations. This repository explores both the advantages and disadvantages of the technique, providing an evaluation based on real experiments conducted in a controlled environment.

## Repository Structure

- `src/`: Directory containing the C source codes used in the experiments and the python codes to generate the graphics
- `docs/`: Documentation of the project and the experimental results in PDF format.
- `img/`: Graphs and other images generated as part of the result analysis.
- `data/`: Contains the data generated in the experimentation

## How to Run

To run the programs in this repository, you will need a setup that can compile and run C programs, as well as tools for performance and cache analysis if you wish to perform detailed evaluations.

To compile the code:
´´´
gcc -o unrolling src/unrolling.c -O0
´´´

And then to execute it:

```
valgrind --tool=cachegrind ./unrolling <array size> <iterations>
```


## Contributions

Contributions are welcome. If you wish to improve the experiments or suggest new optimization techniques, please consider forking the repository and submitting a pull request.

## License

This project is licensed under the MIT License - see the `LICENSE` file for details.

## Authors

- Pablo Seijo