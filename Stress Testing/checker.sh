for ((i = 1; ; ++i)); do
    echo "Test $i:"
    ./gen > input
    ./num < input > output1
    ./good < input > output2
    diff -w output1 output2 || break
    echo "Passed test $i"
done

//to run (bash checker.sh) in total 3 file.
// 1. gen.cpp 2. num.cpp 3. good.cpp
