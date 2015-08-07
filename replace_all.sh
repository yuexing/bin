#!/bin/sh

if [ $# -lt 3 ]; then
  echo "Usage: <to-be-replaced> <replace> file \n";
  exit -1;
fi

echo "sed -e \"s/\\b$1\\b/$2/g\" $3 \n";


function recurse() {

for i in `ls $3`; do
  cur="$3/$i";
  echo $cur;

  if [ -d $cur ]; then 
    recurse $1 $2 $cur;
  else
    mv $cur $cur.bak;
    sed -e "s/\b$1\b/$2/g" $cur.bak > $cur;
    rm $cur.bak
  fi
done

}

recurse $1 $2 $3;
