# Replace all of Il2CppInspector's Unity header resources with the customized headers we've produced in extract.py

$il2cppiPath         = "F:\Source\Repos\Il2CppInspector\Il2CppInspector.Common\Cpp\UnityHeaders"

$metadata = @{
	"5.3.0" = 16;
	"5.3.2" = 19;
	"5.3.3" = 20;
	"5.3.5" = 21;
	"5.5.0" = 22;
	"5.6.0" = 23;
	"2017.1.0" = 24;
	"2018.3.0" = 24.1;
	"2019.1.0" = 24.2;
	"2019.3.7" = 24.3;
	"2019.4.15" = 24.4;
	"2020.1.0" = 24.3;
	"2020.1.11" = 24.4;
	"2020.2.0" = 27
};

$firstVersion        = (ls -File -Filter "5*.h" $PSScriptRoot | select -First 1).Name
$headersStartVersion = ,$firstVersion + (cat "$PSScriptRoot/diffs.diff" | Select-String -Pattern '\+\+\+' | % { $_ -replace '\+\+\+ ', '' })
$headersEndVersion   = cat "$PSScriptRoot/diffs.diff" | Select-String -Pattern '---' | % { $_ -replace '--- ', '' }

If ($headersStartVersion.Length -ne $headersEndVersion.Length + 1) {
	Write-Error "diff file corrupted!"
	Exit
}

rm "$il2cppiPath\*.h"

For ($i = 0; $i -lt $headersStartVersion.Length; $i++) {
	$sourceName      = $headersStartVersion[$i]

	$targetNameStart = $headersStartVersion[$i] -replace "[abfp][0-9]+\.h", ""

	if ($metadata.ContainsKey($targetNameStart)) {
		$metadataVersion = $metadata.$targetNameStart
	}

	$targetNameEnd   = $headersEndVersion[$i]   -replace "[abfp][0-9]+\.h", ""
	$targetName      = "$metadataVersion-$targetNameStart-$targetNameEnd.h"
	if ($targetNameStart -eq $targetNameEnd) {
		$targetName  = "$metadataVersion-$targetNameStart.h"
	}

	echo "$sourceName -> $targetName"
	cp "$PSScriptRoot\$sourceName" -Destination "$il2cppiPath\$targetName"
}