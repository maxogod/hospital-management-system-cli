$sourceFiles = @(
    ".\src\system.c",
    ".\src\records\record.c",
    ".\src\file_manager\file_manager.c"
)
$outputFile = "hospital_system"

$gccCommand = "gcc " + ($sourceFiles -join " ") + " -o $outputFile"

Invoke-Expression $gccCommand
