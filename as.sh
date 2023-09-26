remot="C08"

git remote add "$remot" git@vogsphere.42abudhabi.ae:vogsphere/intra-uuid-642a7868-98e9-40b7-a3db-f4ce916c7018-4757844-mhashir
git fetch "$remot"
git merge "$remot/master" --allow-unrelated-histories -m "commited $remot"
mv ex* "./Piscine/$remot"
git add .
git commit -m "committed $remot"
git push origin master

# for i in {5..8}; do 
#     mkdir "C0$i"       
# done