# Intro

These are a collection of steganography related challenges for the UWE Falcons Team to complete at their own pace. The majority of these challenges revolve around steganography, including steg. within the context of malware analysis.

# Flag Format

All flags are given in the format `flag{FLAG_HERE}`. 

# Resources 

- https://ctf101.org/forensics/what-is-stegonagraphy/
- https://infosecwriteups.com/some-common-steganography-tools-for-ctfs-92e3de93f141
- https://noob-atbash.github.io/CTF-writeups/nahamcon-20/stego/stego.html
- https://medium.com/@FourOctets/ctf-tidbits-part-1-steganography-ea76cc526b40
- https://steghide.sourceforge.net/

# Writeup
---

## PCAP 1
To complete this challenge, open pcap1.pcapng in Wireshark, in the context menu under "File" select "export objects" then "HTTP", scroll down and select "meow.png" then select save.

flag{PC4P_4_FL4GZ}

## DJ Khaled
To complete this challenge, open KhaledRizz.webp in HxD, search for the known text "flag/{" from the context menu "Search" under "Find" which will take you to the flag.

flag{alw4y3_l00k_4_5tr1n9s}

## Shreck
To complete this challenge, open shrek.gif in GIMP, go layer by layer hiding them until text is visible at the bottom of frame 16.

flag{g3t_shr3k3d_sk1d}

## Hard
Open the document in word, enable macros to allow the [token stealer](https://github.com/polygonben/polygonben.github.io/raw/refs/heads/master/assets/images/tok3n_th3ft.dll) to run (If the macro isn't safe then we get to sue someone:] ), the token stealer macro can be viewed from MS Word under "View" then "Macros" then "View Macros"

The dll when decompiled using jetbrains dotpeak gives a C# function "main" which when altered slightly to run and display the resulting string outputs a base64 encoded pkzip file
output: "UEsDBAoACQAAAO08hFlaSTFRLQAAACEAAAAEABwAZmxhZ1VUCQADfk1QZ65NUGd1eAsAAQToAwAABOgDAAAze2117XaFyLM5GqYAiwssznvxoWrz9PHhfyYZPTt+dcOTv1ZAEpeQxbojhJJQSwcIWkkxUS0AAAAhAAAAUEsBAh4DCgAJAAAA7TyEWVpJMVEtAAAAIQAAAAQAGAAAAAAAAQAAALSBAAAAAGZsYWdVVAUAA35NUGd1eAsAAQToAwAABOgDAABQSwUGAAAAAAEAAQBKAAAAewAAAAAA"

This password protected zip file can be cracked using rockyou.txt to get the password "redfalcon2008" which allows for "flag" to be extracted with contents:

flag{very_good_work_contact_me!}

## Steghide 1
Using steghide with no passphrase, the file stage.ps1 can be extracted which contains the base64 encoded string "ZmxhZ3tuMHRfdG9vX2g0cmRfcmlnaHQ/fQ==" which is "flag{n0t_too_h4rd_right?}"

flag{n0t_too_h4rd_right?}

## Steghide 2
Using fotoforensics.com, a JPEG comment contains "XHey GCHQ! Use this for the st3gh1d3 pwd (remember to decode it!): ==wL6kHdpJXdjV2UyJ3R" which when reversed and decoded to base64 reads "GrrSecurity:/", which when used with steghide to extract a hidden file gives "flag" which contains a base64 encoded bzip2 compressed string "flag{g3tting_h4rd3r_n0w}"

flag{g3tting_h4rd3r_n0w}