$sourceFiles = @(
    ".\src\system.c",
    ".\src\records\record.c",
    ".\src\file_manager\file_manager.c"
)
$outputFile = "test"

$gccCommand = "gcc " + ($sourceFiles -join " ") + " -o $outputFile"

Invoke-Expression $gccCommand
