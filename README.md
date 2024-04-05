# LLVM-PASS
LLVM PASS design to identify memory intensive region in a Python Application

- Our task was to write a llvm pass for a python application that identifies memory-
intensive region (functions) in it and mention that function along with the desired
block-id (numbers are good to go).

- Memory-intensive regions in a program are portions of code that require significant
amounts of memory to execute efficiently. These regions often involve operations
that manipulate large data and involve Data Processing, Numerical Computation,
Dynamic Memory Allocation, I/O operations etc.

- Since there is no mention as to what might be memory intensive, we may include a
threshold value and if function in program crosses that threshold, we may identify it
as identifies memory-intensive region.

Installation & download of llvm :

For Linux based :
- $ sudo apt-get update
- $ sudo apt-get install clang llvm
For MAC OS based :
- $ brew install llvm


Conversion of application file to .ll file :

For Python Application : It is advised to convert the given .py application to
c/cpp application as it is easier to form .ll file for them. This can be done using
various libraries like Cython or OpenAI CodeX.

- For using CodeX :
  
        Register on openAI API @ https://platform.openai.com/api-keys
        Generate the api key and add it to environment file, i.e. .env file
        Create a virtual environment using : python -m venv path_of_folder
        pip install openai
        pip install os
        pip install dotenv

- To compile it :
          python3 script.py
          C/Cpp Application to .ll File :
          clang -S -emit-llvm <file_name>.c -o <file_name>.ll
  
Optimization Technique with LLVM Pass :

        - Optimizations are implemented as Passes that traverse some portion of a program to either
        collect information or transform the program. Here we have to identify memory intensive
        regions. Functions used for intended work has been provided by llvm pass header files.
        
- To compile the llvmpass file :
$ clang++ -shared -o <llvm_pass_filename>.so <llvm_pass_filename>.cpp `llvm-config --cxxflags --
ldflags --libs` -fPIC
$ opt -load ./<llvm_pass_filename>.so -instruction-counter < {app_file_name}.ll >
/dev/null
