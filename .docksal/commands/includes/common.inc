#-------------------------- Helper functions --------------------------------

# Console colors
red='\033[0;31m'
green='\033[0;32m'
green_bg='\033[42m'
yellow='\033[1;33m'
NC='\033[0m'

echo-red() { echo -e "${red}$1${NC}"; }
echo-green() { echo -e "${green}$1${NC}"; }
echo-green-bg() { echo -e "${green_bg}$1${NC}"; }
echo-yellow() { echo -e "${yellow}$1${NC}"; }

# Yes/no confirmation dialog with an optional message
# @param $1 confirmation message
# @param $2 --no-exit
# Source bin/fin
_confirm() {
  # Skip checks if not running interactively (not a tty or not on Windows)
  if ! is_tty; then return 0; fi

  while true; do
    echo -en "$1 "
    read -p "[y/n]: " answer
    case "$answer" in
    [Yy] | [Yy][Ee][Ss])
      break
      ;;
    [Nn] | [Nn][Oo])
      [[ $2 == "--no-exit" ]] && return 1
      exit 1
      ;;
    *)
      echo 'Please answer yes or no.'
      ;;
    esac
  done
}

# Copy a settings file.
# Skips if the destination file already exists.
# @param $1 source file
# @param $2 destination file
copy_settings_file()
{
	local source="$1"
	local dest="$2"

	if [[ ! -f $dest ]]; then
		echo "Copying ${dest}..."
		cp $source $dest
	else
		echo "${dest} already in place."
	fi
}
#-------------------------- END: Helper functions --------------------------------
