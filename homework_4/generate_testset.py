import os
import random
import sys

def write_list_to_file(filepath, write_list):
    with open(filepath, 'w') as file:
        for value in write_list:
            file.write(str(value) + " ")

def generate_testdata(testset_folder, testset_name, max_range):
    data = [random.randrange(max_range) for count in range(3000)]
    data_path = os.path.join(testset_folder, testset_name + ".txt")
    write_list_to_file(data_path, data)
    data.sort()
    sorted_data_path = \
        os.path.join(testset_folder, testset_name + "_sorted.txt")
    write_list_to_file(sorted_data_path, data)

if __name__ == "__main__":
    assert len(sys.argv) == 4, "Need exactly two arguments"
    testset_folder = sys.argv[1]
    testset_name = sys.argv[2]
    max_range = int(sys.argv[3])
    generate_testdata(testset_folder, testset_name, max_range)
