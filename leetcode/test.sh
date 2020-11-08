repo=`hub remote get-url origin`
if [[ $repo =~ "github.com/negibokken" ]]; then
  echo "hi"
fi
