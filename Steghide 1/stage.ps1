$e1 = "ZmxhZ3tuMHRfdG9vX2g0cmRfcmlnaHQ/fQ=="
$b2 = "JABTAEgARQBMTAAgAD0AIAAoAEkAbgB2AG8AawBlACgAKABbAFMAdAByAGkAbgBnAF0AKABJAE4AVABFAGcAcgBhAHQAaQBuAGcAIAAnAFMAQQBOAFQAOQAnACwAIAAnAEcATgBPAFAAVABFAEwARQBOAFQAJwApACkAKQApAA=="
$randVars = ('R1', 'l4', 'fG', 'mA', 'Xy', 'b6', 'Az', 'dJ') | Get-Random -Count 4
Set-Variable -Name ($randVars[0]) -Value ([System.Text.Encoding]::UTF8.GetString([Convert]::FromBase64String($encodedCommand)))
Set-Variable -Name ($randVars[1]) -Value ([System.Text.Encoding]::UTF8.GetString([Convert]::FromBase64String($base64Encoded)))
Set-Variable -Name ($randVars[2]) -Value ([String]::Join('', @($($randVars[0]), $($randVars[1]))))
iex $(Invoke-Expression "$($randVars[2])")
