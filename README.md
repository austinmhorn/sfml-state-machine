<h1><p align="center"><b>MacOS:</b></p></h1>

<h2><p align="center"><i>Install or upgrade <a href="https://brew.sh">Homebrew</a>: </i></p></h2>

    if [[ $(command -v brew) == "" ]]; then
    echo "Installing Homebrew"
    /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
    else
        echo "Updating Homebrew"
        brew upgrade
    fi

<h1><p align="center"><b>WSL:</b></p></h1>

- 1) Navigate to your home directory for your user on the local computer. You can check that the path is correct because it DOES NOT have OneDrive in the path when printing with pwd.<br>
- 2) Then go here: https://brew.sh/ <br>
- 3) Copy the link starting with "/bin/bash -c ... " <br>
- 4) Paste and run the command in that directory of your shell. <br>

---
        
<h2><p align="center"><i>Then, use it to install <a href="https://www.sfml-dev.org">SFML</a>: </i></p></h2>

    brew install sfml
    
<h2><p align="center"><i>Verify installation with: </i></p></h2>
    
    brew list sfml
            
<h2><p align="center"><i>Clone this repo: </i></p></h2>

    git clone https://github.com/austinmhorn/sfml-state-machine.git

<h2><p align="center"><i>Move to project source directory: </i></p></h2>

    cd sfml-state-machine
    
 <h2><p align="center"><i>Configure binaries: </i></p></h2>

    cmake -S . -B build

 <h2><p align="center"><i>Build binaries: </i></p></h2>

    cmake --build build
    
 <h2><p align="center"><i>Run executable: </i></p></h2>

    ./sfml-state-machine
