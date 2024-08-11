#/bin/bash

# *****************************************
# Author: tphiepbk
# *****************************************

filename="$1"

if [[ -z "${filename}" ]]; then
    echo "Please enter filename"
    exit 1
fi

problem="${filename%.*}"

# Replace <problem> and <filename> in Makefile
sed -i "s/<filename>/${filename}/g" Makefile
sed -i "s/<problem>/${problem}/g" Makefile

# Run make
echo "====================================================="
echo "Running make..."
make
if [[ "$?" != 0 ]]; then
    echo "Make error"
    exit 2
fi

# Run program
echo "====================================================="
echo "Running program ${problem}..."
./codeforces

# Revert
sed -i "s/${filename}/<filename>/g" Makefile
sed -i "s/${problem}/<problem>/g" Makefile

# Copy program to submission folder
codeforces_submission_dir="/mnt/c/Users/thanh/Desktop/codeforces_submission"

echo "====================================================="
echo "Copying program ${problem} to submission folder ${codeforces_submission_dir}..."

if [[ ! -d "${codeforces_submission_dir}" ]]; then
    mkdir -p "${codeforces_submission_dir}"
fi

cp "${filename}" "${codeforces_submission_dir}"

