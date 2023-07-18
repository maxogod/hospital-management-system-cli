$sourceFiles = @(
    ".\src\tests\run_tests.c",
    ".\src\tests\record_test.c",
    ".\src\records\record.c",
    ".\src\file_manager\file_manager.c" 
)
$outputFile = "test"

$gccCommand = "gcc " + ($sourceFiles -join " ") + " -o $outputFile"

Invoke-Expression $gccCommand
