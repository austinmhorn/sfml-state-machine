<h1>
    <p align="center">sfml-state-machine</p>
</h1>

Check for <a href="https://brew.sh">Homebrew</a> (a multifarious package manager for macOS or Linux):

    brew --version

If you don't have it, install it:

    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

You will need <a href="https://cmake.org">CMake</a> to build the project (an open-source, cross-platform, build system generator):

    brew install cmake

I recommend you also install <a href="https://git-scm.com">Git</a> to easily clone this repository: 

    brew install git

Clone this repository

    git clone https://github.com/austinmhorn/sfml-state-machine.git

Move into project source directory

    cd sfml-state-machine

Compile source files

     cmake -S . -B build

Build objects and link executable
    
     cmake --build build --config Release

Run executable

    ./sfml-state-machine

---

If you run into any errors building the SFML library, run this command to install its dependencies:

    sudo apt-get install build-essential libx11-dev libgl1-mesa-dev libxrandr-dev libxcursor-dev libudev-dev libopenal-dev libvorbis-dev libflac-dev libfreetype6-dev
