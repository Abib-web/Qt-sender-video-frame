#!/bin/bash

# Nettoyage
echo "🧹 Nettoyage des anciens fichiers..."
rm -f Makefile *.o *.user *.pro.user app_send_frame

# Génération du fichier .pro si nécessaire
if [ ! -f app_send_frame.pro ]; then
    echo "📦 Génération de app_send_frame.pro..."
    qmake -project
fi

# Ajout du support pour les .ui
echo "🔧 Ajout de la compilation UI au .pro..."
grep -q "FORMS +=" app_send_frame.pro || echo "FORMS += mainwindow.ui" >> app_send_frame.pro

# Génération du Makefile
echo "⚙️ Génération du Makefile avec qmake..."
qmake app_send_frame.pro

# Compilation
echo "🔨 Compilation..."
make

# Exécution
if [ -f ./app_send_frame ]; then
    echo "🚀 Lancement de l'application..."
    ./app_send_frame
else
    echo "❌ Erreur : binaire introuvable"
fi
