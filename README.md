# Elise

Inspired by Joseph Weizenbaum’s Eliza, Elise is a program written in C which accepts natural English as its input, and carries out a coherent conversation.

## Motivation
Technology is reaching a precarious point, where most people are having a hard time understanding it. This will create uncertainty, and it will lead to problems, unless we address it. This is my attempt to do so.

Elise, which is inspired by Eliza, is a simple version of a chatbot. The program parses your inputs, and then manipulates them in order to produce a convincing output. Hopefully, this will help shed some light on how this technology works.

## Quick Start

Navigate to the project directory, and create a binary file.

```bash
gcc elise.c -o build/elise && ./build/elise
```

## Usage

Run the binary, and have fun. Please bear in mind that the current version does not handle punctuation and upper case well.

## Contribution

Would you like to help improve the responses? You can run a simple command which will record the output, and save it into a .txt file. You can then email it to me, and I can use that to improve Elise’s responses.

Please make sure not to include any personal information that you don’t want to be publicly known.

For macOS, here is the command, assuming you’re running it from the main project directory.

```bash
script -q output.txt ./build/elise
```

If you’re running Linux, this command should work.

```bash
script -q -c './build/elise' output.txt
```

If you’re unfortunate enough to run Windows, this _should_ be the PowerShell equivalent.

```powershell
.\build\elise.exe 2>&1 | Tee-Object -FilePath output.txt
```
