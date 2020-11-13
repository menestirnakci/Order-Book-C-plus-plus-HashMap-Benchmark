import numpy as np
import os
import os.path
from os import path

a = path.exists('results.txt')
if a:
    out = open('results.txt', 'r+')
    os.remove("results.txt")

add_result_file = open("add_results.txt", "r")
execute_file = open("execute_results.txt", "r")
delete_file = open("delete_results.txt", "r")

add_results_array = add_result_file.read().split('\n')
execute_results_array = execute_file.read().split('\n')
delete_results_array = delete_file.read().split('\n')

add_results_array.pop()
execute_results_array.pop()
delete_results_array.pop()


def save_results(arr, orderType):
    outfile = open('results.txt', 'a')
    for i in range(0, len(arr)):
        arr[i] = int(arr[i])
    mean = 'mean \t\t' + str(round(np.mean(arr), 2)) + '\n'
    std = 'std \t\t' + str(round(np.std(arr), 2)) + '\n'
    min = 'min \t\t' + str(np.min(arr)) + '\n'
    max = 'max \t\t' + str(np.max(arr)) + '\n'
    q1 = '%1 quantile \t' + str(round(np.quantile(arr, .1), 2)) + '\n'
    q25 = '%25 quantile \t' + str(round(np.quantile(arr, .25), 2)) + '\n'
    q50 = '%50 quantile \t' + str(round(np.quantile(arr, .50), 2)) + '\n'
    q75 = '%75 quantile \t' + str(round(np.quantile(arr, .75), 2)) + '\n'
    q99 = '%99 quantile \t' + str(round(np.quantile(arr, .99), 2)) + '\n'
    q999 = '%99,9 quantile \t' + str(round(np.quantile(arr, .999), 2)) + '\n'
    title = '----------' + orderType + ' RESULT----------\n'
    outfile.write(title)
    outfile.write(mean)
    outfile.write(std)
    outfile.write(min)
    outfile.write(max)
    outfile.write(q1)
    outfile.write(q25)
    outfile.write(q50)
    outfile.write(q75)
    outfile.write(q99)
    outfile.write(q999)

save_results(add_results_array, 'ADD')
save_results(execute_results_array, 'EXECUTE')
save_results(delete_results_array, 'DELETE')
global_array = add_results_array + execute_results_array + delete_results_array
save_results(global_array, 'GLOBAL')

