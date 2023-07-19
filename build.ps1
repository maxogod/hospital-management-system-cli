$sourceFiles = @(
    ".\src\system.c",
    ".\src\records\record.c",
    ".\src\file_manager\file_manager.c"
    ".\src\cli_printer\io.c"
    ".\src\utils\utils.c"
)
$outputFile = "hospital_system"

$gccCommand = "gcc " + ($sourceFiles -join " ") + " -o $outputFile"

Invoke-Expression $gccCommand
