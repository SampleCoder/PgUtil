#!/bin/bash
printf "Enter pass: "
read -s pwd
echo ""
./testpq "$pwd"
unset pwd
