import os
import random

class Test:
    def __init__(self, mutator, description, source, expected):
        self.mutator = mutator
        self.description = description
        self.source = source
        self.expected = expected

    def run(self):
        print(f"Running {self.mutator}: {self.description}")
        # get current dir
        current_dir = os.getcwd()

        # create temporary directory /tmp/chernobyl/test_{self.mutator}_RANDOM
        dir_name = f"/tmp/chernobyl/test_{self.mutator}_" + str(random.randint(0, 1000000000))
        os.system(f"mkdir -p {dir_name}")
        # set working directroy
        os.chdir(dir_name)
        os.system(f"echo '{self.source}' > sample.cpp")
        os.system(f"bear -- g++ sample.cpp")
        os.system(f"clang-tidy-16 --quiet -fix -load={current_dir}/build/libbitcoin-mutator.so -checks='mutator-{self.mutator}' sample.cpp > /dev/null 2>&1")

        # read the file
        with open("sample.cpp") as f:
            result = f.read()
            result = result[:-1]

        # compare the result
        if result != self.expected:
            print("FAILED")
            print("Expected:")
            print(self.expected)
            print("Got:")
            print(result)

tests = [
    Test(
        "and-to-or", 
        "simple", 
'''
    #include <iostream>

    int main() {
        if (true && false) {
            std::cout << "true && false" << std::endl;
        }
    }
''', 
'''
    #include <iostream>

    int main() {
        if (true || false) {
            std::cout << "true && false" << std::endl;
        }
    }
'''),
]

for test in tests:
    test.run()
