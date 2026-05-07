rule Team5_Payload_Detection
{
    meta:
        author = "Jahir"
        description = "Detecta el binario team5_payload.exe"
        date = "2026-05-07"

    strings:

        $ps1 = "powershell -EncodedCommand" ascii wide
        $calc = "calc.exe" ascii wide
        $localhost = "127.0.0.1" ascii wide
        $http = "http://127.0.0.1:8080" ascii wide

        $va = "VirtualAlloc" ascii wide
        $we = "WinExec" ascii wide
        $iu = "InternetOpenUrlA" ascii wide

        $menu = "TEAM PAYLOAD MENU" ascii wide

    condition:
        4 of them
}