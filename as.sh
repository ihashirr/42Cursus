remot="C07"

git remote add "$remot" git@vogsphere.42abudhabi.ae:vogsphere/intra-uuid-1c3c14f0-7fec-415c-93a6-c75dceb548ff-4757460-mhashir
git fetch "$remot"
git merge "$remot/master" --allow-unrelated-histories -m "commited $remot"
mv ex* "./Piscine/$remot"
git add .
git commit -m "committed $remot"
git push origin master

# for i in {5..8}; do 
#     mkdir "C0$i"       
# done