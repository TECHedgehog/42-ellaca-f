find . -type f -name "*.sh" -exec basename {} \; | rev | cut -d "." -f2- | rev 
