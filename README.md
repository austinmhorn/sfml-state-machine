
<h2><p align="center"><i>Install/Upgrade Homebrew (multifarious package manager): </i></p></h2>

    if [[ $(command -v brew) == "" ]]; then
    echo "Installing Homebrew"
    /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
    else
        echo "Updating Homebrew"
        brew upgrade
    fi
        
<h2><p align="center"><i>Then, use it to install SFML: </i></p></h2>

    brew install sfml
            
<h2><p align="center"><i>Clone this repo: </i></p></h2>

    git clone https://github.com/austinmhorn/sfml-state-machine.git

<h2><p align="center"><i>Move to project source directory: </i></p></h2>

    cd sfml-state-machine
    
 <h2><p align="center"><i>Configure binaries: </i></p></h2>

    cmake -S . -B build

 <h2><p align="center"><i>Build binaries: </i></p></h2>

    cmake --build build
    
 <h2><p align="center"><i>Run executable: </i></p></h2>

    ./StateMachineApplication
