remot="C05"

git remote add "$remot" git@vogsphere.42abudhabi.ae:vogsphere/intra-uuid-6fab5b67-09bb-4bc3-a1aa-89da637b3cd5-4756966-mhashir
git fetch "$remot"
git merge "$remot/master" --allow-unrelated-histories -m "commited $remot"
mv ex* "./Piscine/$remot"
git add .
git commit -m "committed $remot"
git push origin master

# for i in {5..8}; do 
#     mkdir "C0$i"       
# done