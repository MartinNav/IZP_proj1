#
# Tests for 1. IZP project [2023]
# Author: _ramb0_
# Usage:
#     ./test_keyfilter.ps1


# Color codes
$RED = [ConsoleColor]::Red
$GREEN = [ConsoleColor]::Green
$NC = [ConsoleColor]::Black

# Compile the program
gcc.exe -std=c11 -Wall -Wextra -Werror keyfilter.c -o keyfilter.exe

function run_test($input_file, $test_arg, $expected_output) {
    Write-Host -NoNewline "Running test with input from $input_file and argument ${test_arg:0:10}... "

    $actual_output = .\keyfilter.exe $test_arg '<' $input_file

    if ($actual_output -eq $expected_output) {
        Write-Host -ForegroundColor $GREEN "PASSED" -NoNewline
    } else {
        Write-Host -ForegroundColor $RED "FAILED" -NoNewline
        Write-Host "Expected: $expected_output"
        Write-Host "Got:      $actual_output"
    }
}

# Test cases
echo "Praha\nBrno\nBruntal\nBratislava" '>' test_01.txt

run_test "test_01.txt" "" "Enable: BP"

run_test "test_01.txt" "b" "Enable: R"
run_test "test_01.txt" "B" "Enable: R"

run_test "test_01.txt" "br" "Enable: ANU"
run_test "test_01.txt" "BR" "Enable: ANU"

run_test "test_01.txt" "brn" "Found: BRNO"
run_test "test_01.txt" "BRN" "Found: BRNO"

run_test "test_01.txt" "be" "Not found"
run_test "test_01.txt" "BE" "Not found"

# More complex file
echo "Praha\nBrno\nBruntal\nBratislava\nBerlin\nBudapest\nPrague\nBrunswick\nBritain\nBrazil\nBremen" '>' test_02.txt

run_test "test_02.txt" "" "Enable: BP"

run_test "test_02.txt" "b" "Enable: ERU"

run_test "test_02.txt" "br" "Enable: AEINU"
run_test "test_02.txt" "BR" "Enable: AEINU"

run_test "test_02.txt" "bru" "Enable: N"
run_test "test_02.txt" "BRU" "Enable: N"

run_test "test_02.txt" "brun" "Enable: ST"

run_test "test_02.txt" "brunt" "Found: BRUNTAL"

run_test "test_02.txt" "be" "Found: BERLIN"

run_test "test_02.txt" "ber" "Found: BERLIN"

run_test "test_02.txt" "berl" "Found: BERLIN"

run_test "test_02.txt" "bremen" "Found: BREMEN"

run_test "test_02.txt" "p" "Enable: R"

echo "TohleJeTestNaStoCharakteruDlouhejRadekJestliNahodouJsiTamNeudelalChybickuFrajereJustAskingYouKnowHeh" '>' test_03.txt

run_test "test_03.txt" "to" "Found: TOHLEJETESTNASTOCHARAKTERUDLOUHEJRADEKJESTLINAHODOUJSITAMNEUDELALCHYBICKUFRAJEREJUSTASKINGYOUKNOWHEH"

Remove-Item -Path "test_03.txt"
Remove-Item -Path "test_02.txt"
Remove-Item -Path "test_01.txt"