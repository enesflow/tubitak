# remove all files in the current directory without an extension

find . -type f  ! -name "*.*" -not -path "*/.git/*"  -delete -print