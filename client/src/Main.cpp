#include <iostream>
#include <string>
#include <unistd.h>
#include "cmath"
#include "../include/FormeSauvegarder.h"
#include "../include/FormeDessiner.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

#ifndef M_PI_2
    #define M_PI_2 1.57079632679489661923
#endif

#ifndef M_PI_4
    #define M_PI_4 0.78539816339744830961
#endif

using namespace std;
int main() {
    try {
        ///TEST SEGMENT///
        cout << "--------------------------" << endl;
        cout << "       TEST SEGMENT" << endl;
        cout << "--------------------------" << endl;
        auto * s = new Segment, * s1 = new Segment(3,3,5,5), * s2 = new Segment(Vecteur2D(1,3), Vecteur2D(-5, -3)), * s3 = new Segment (3,3,5,5, Couleur::RED), * sr = new Segment(Vecteur2D(1,3), Vecteur2D(-5, -3), Couleur::CYAN);
        cout << *s << endl << *s1 << endl << *s2 << endl << *s3 << endl << *sr << endl;
        try {
            Segment erreur(1,1,1,1);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            Segment erreur(Vecteur2D(1,1),Vecteur2D(1,1));
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << sr->getp1() << endl;
        cout << sr->getp2() << endl;
        cout << sr->setp1(-5, -2) << endl;
        cout << sr->setp2(-3, -6) << endl;
        try {
            sr->setp2(-5, -2);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            sr->setp1(-3, -6);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        auto points = sr->getPoints();
        for (auto it : points) {
            cout << it << endl;
        }
        vector<Vecteur2D> newpoints;
        newpoints.emplace_back(-2, -2);
        newpoints.emplace_back(-3, -3);
        cout << sr->setPoints(newpoints) << endl;
        newpoints.emplace_back(-4, -4);
        try {
            sr->setPoints(newpoints);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        newpoints.clear();
        newpoints.emplace_back(-2, -2);
        newpoints.emplace_back(-2, -2);
        try {
            sr->setPoints(newpoints);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << sr->getAire() << endl;
        cout << sr->translation(Vecteur2D(3, 3)) << endl;
        cout << sr->translation(Vecteur2D(-3, -3)) << endl;
        cout << sr->homothetie(Vecteur2D(-1,-1), 2) << endl;
        cout << sr->homothetie(Vecteur2D(-1,-1), 0.5) << endl;
        try {
            sr->homothetie(Vecteur2D(-1,-1), 0);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << sr->rotation(Vecteur2D(0,0), M_PI_2) << endl;
        cout << sr->rotation(Vecteur2D(0,0), M_PI_4) << endl;
        cout << sr->rotation(Vecteur2D(0,0), M_PI_4) << endl;
        cout << sr->rotation(Vecteur2D(0,0), -M_PI) << endl;
        FormeSauvegarder sauvegarder("Segment.txt");
        sr->accept(sauvegarder);
        Forme * srprime = Forme::charger("Segment.txt");
        cout << * srprime << endl;
        delete s; delete s1; delete s2; delete s3; delete srprime;

        ///TEST CERCLE///
        cout << "--------------------------" << endl;
        cout << "       TEST CERCLE" << endl;
        cout << "--------------------------" << endl;
        auto * c = new Cercle, * c1 = new Cercle(3,3,5), * c2 = new Cercle(Vecteur2D(1,3), 3), * c3 = new Cercle (3,3,5, Couleur::RED), * cr = new Cercle(Vecteur2D(1,3), 4, Couleur::CYAN);
        cout << *c << endl << *c1 << endl << *c2 << endl << *c3 << endl << *cr << endl;
        try {
            Cercle erreur(1,1, 0);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            Cercle erreur(Vecteur2D(1,1),0);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << cr->getc() << endl;
        cout << cr->getr() << endl;
        cout << cr->setc(-5, -2) << endl;
        cout << cr->setr(6) << endl;
        try {
            cr->setr(-6);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        auto pointsc = sr->getPoints();
        for (auto it : pointsc) {
            cout << it << endl;
        }
        vector<Vecteur2D> newpointsc;
        newpointsc.emplace_back(-2, -2);
        newpointsc.emplace_back(-4, -4);
        newpointsc.emplace_back(0, 0);
        cout << cr->setPoints(newpointsc) << endl;
        try {
            cr->setPoints({Vecteur2D(2,2), Vecteur2D(-2,-2), Vecteur2D(-2,-2)});
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        newpointsc.clear();
        newpointsc.emplace_back(-2, -2);
        newpointsc.emplace_back(-2, -2);
        try {
            cr->setPoints(newpointsc);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << cr->getAire() << endl;
        cout << cr->translation(Vecteur2D(3, 3)) << endl;
        cout << cr->translation(Vecteur2D(-3, -3)) << endl;
        cout << cr->homothetie(Vecteur2D(-1,-1), 2) << endl;
        cout << cr->homothetie(Vecteur2D(-1,-1), 0.5) << endl;
        try {
            cr->homothetie(Vecteur2D(-1,-1), 0);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << cr->rotation(Vecteur2D(0,0), M_PI_2) << endl;
        cout << cr->rotation(Vecteur2D(0,0), M_PI_4) << endl;
        cout << cr->rotation(Vecteur2D(0,0), M_PI_4) << endl;
        cout << cr->rotation(Vecteur2D(0,0), -M_PI) << endl;
        FormeSauvegarder sauvegarderc("Cercle.txt");
        cr->accept(sauvegarderc);
        Forme * crprime = Forme::charger("Cercle.txt");
        cout << * crprime << endl;
        delete c; delete c1; delete c2; delete c3; delete crprime;

        ///TEST TRIANGLE///
        cout << "--------------------------" << endl;
        cout << "       TEST TRIANGLE" << endl;
        cout << "--------------------------" << endl;
        auto * t = new Triangle, * t1 = new Triangle(3,3,5,5), * t2 = new Triangle(Vecteur2D(1,3), Vecteur2D(-5, -3), Vecteur2D(1,1)), * t3 = new Triangle (3,3,5,5, 1, 1, Couleur::GREEN), * tr = new Triangle(Vecteur2D(1,3), Vecteur2D(-5, -3), Vecteur2D(1,1), Couleur::YELLOW);
        cout << *t << endl << *t1 << endl << *t2 << endl << *t3 << endl << *tr << endl;
        try {
            Triangle erreur(1,1,1,1, 2, 2);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            Triangle erreur(Vecteur2D(1,1),Vecteur2D(1,1), Vecteur2D(2,2));
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << tr->getp1() << endl;
        cout << tr->getp2() << endl;
        cout << tr->getp3() << endl;
        cout << tr->setp1(-5, -2) << endl;
        cout << tr->setp2(-3, -6) << endl;
        cout << tr->setp3(0, 0) << endl;
        try {
            tr->setp3(-3, -6);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            tr->setp2(-5, -2);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            tr->setp1(0, 0);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        auto pointst = tr->getPoints();
        for (auto it : pointst) {
            cout << it << endl;
        }
        vector<Vecteur2D> newpointst;
        newpointst.emplace_back(-2, -2);
        newpointst.emplace_back(2, -2);
        newpointst.emplace_back(2, 2);
        cout << tr->setPoints(newpointst) << endl;
        newpointst.emplace_back(-4, -4);
        try {
            tr->setPoints(newpointst);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        newpointst.clear();
        newpointst.emplace_back(-2, -2);
        newpointst.emplace_back(-3, -3);
        newpointst.emplace_back(-2, -2);
        try {
            tr->setPoints(newpointst);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << tr->getAire() << endl;
        cout << tr->translation(Vecteur2D(3, 3)) << endl;
        cout << tr->translation(Vecteur2D(-3, -3)) << endl;
        cout << tr->homothetie(Vecteur2D(-1,-1), 2) << endl;
        cout << tr->homothetie(Vecteur2D(-1,-1), 0.5) << endl;
        try {
            tr->homothetie(Vecteur2D(-1,-1), 0);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << tr->rotation(Vecteur2D(0,0), M_PI_2) << endl;
        cout << tr->rotation(Vecteur2D(0,0), M_PI_4) << endl;
        cout << tr->rotation(Vecteur2D(0,0), M_PI_4) << endl;
        cout << tr->rotation(Vecteur2D(0,0), -M_PI) << endl;
        FormeSauvegarder sauvegardert("Triangle.txt");
        tr->accept(sauvegardert);
        Forme * trprime = Forme::charger("Triangle.txt");
        cout << * trprime << endl;
        delete t; delete t1; delete t2; delete t3; delete trprime;

        ///TEST POLYGONE///
        cout << "--------------------------" << endl;
        cout << "     TEST POLYGONE" << endl;
        cout << "--------------------------" << endl;
        vector<Vecteur2D> v = {Vecteur2D(2,-2), Vecteur2D(2,2), Vecteur2D(-2,2), Vecteur2D(-2,-2)};
        auto * p = new Polygone;
        cout << "ok";
        auto * p1 = new Polygone(Couleur::GREEN);
        cout << "ok";
        auto * pr = new Polygone(v);
        cout << "ok";
        cout << *p << endl << *p1 << endl << *pr << endl;
        try {
            Polygone Polygone({Vecteur2D(2,-2), Vecteur2D(2,2), Vecteur2D(-2,2), Vecteur2D(-2, 2)});
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        auto pointsp = pr->getPoints();
        for (auto it : pointsp) {
            cout << it << endl;
        }
        try {
            pr->setPoints({Vecteur2D(2,2), Vecteur2D(-2,-2), Vecteur2D(2,-2), Vecteur2D(2, 2)});
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << (*pr)[0] << endl;
        try {
            cout << (*pr)[-1];
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            cout << (*pr)[4];
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << *pr + Vecteur2D(0, 0) << endl;
        try {
            cout << *pr + Vecteur2D(0, 0) << endl;
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << *pr - Vecteur2D(0, 0) << endl;
        cout << pr->addPointAt(Vecteur2D(0,0), 0) << endl;
        try {
            pr->addPointAt(Vecteur2D(0,0), 0);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            pr->addPointAt(Vecteur2D(1,1), -1);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            pr->addPointAt(Vecteur2D(1,1), 6);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << pr->removePointAt(0) << endl;
        try {
            pr->removePointAt(4);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            pr->removePointAt(-1);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << pr->modifyPoint(Vecteur2D(2, 2), Vecteur2D(0,0)) << endl;
        cout << pr->modifyPointAt(1, Vecteur2D(2,2)) << endl;
        try {
            pr->modifyPoint(Vecteur2D(2, 2), Vecteur2D(-2,-2));
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            pr->modifyPointAt(-1, Vecteur2D(0,0));
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            pr->modifyPointAt(5, Vecteur2D(0,0));
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            pr->modifyPointAt(0, Vecteur2D(2,2));
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << pr->switchPointAt(0,2) << endl;
        cout << pr->switchPoint(Vecteur2D(-2, 2), Vecteur2D(2, -2)) << endl;
        cout << pr->getAire() << endl;
        cout << pr->translation(Vecteur2D(3, 3)) << endl;
        cout << pr->translation(Vecteur2D(-3, -3)) << endl;
        cout << pr->homothetie(Vecteur2D(-1,-1), 2) << endl;
        cout << pr->homothetie(Vecteur2D(-1,-1), 0.5) << endl;
        try {
            pr->homothetie(Vecteur2D(-1,-1), 0);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << pr->rotation(Vecteur2D(0,0), M_PI_2) << endl;
        cout << pr->rotation(Vecteur2D(0,0), M_PI_4) << endl;
        cout << pr->rotation(Vecteur2D(0,0), M_PI_4) << endl;
        cout << pr->rotation(Vecteur2D(0,0), -M_PI) << endl;
        FormeSauvegarder sauvegarderp("Polygone.txt");
        pr->accept(sauvegarderp);
        Forme * prprime = Forme::charger("Polygone.txt");
        cout << * prprime << endl;
        delete p; delete p1; delete prprime;

        ///TEST FORME COMPOSEE///
        cout << "--------------------------" << endl;
        cout << "   TEST FORME COMPOSEE" << endl;
        cout << "--------------------------" << endl;
        auto * fc = new FormeComposee(), * fc1 = new FormeComposee(Couleur::BLUE), * fcr = new FormeComposee({sr, cr, tr});
        cout << *fc << endl << *fc1 << endl << *fcr << endl;
        auto * clonefcr = fcr->clone();
        cout << *clonefcr << endl;
        delete clonefcr;
        cout << (*fc = *fcr) << endl;
        cout << (*fc1 = *fc) << endl;
        cout << (*fc1 = *fcr) << endl;
        for (auto f : fcr->getFormes()) {
            cout << *f << endl;
        }
        cout << *fcr->getFormeAt(0) << endl;
        try {
            cout << fcr->getFormeAt(-1) << endl;
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            cout << fcr->getFormeAt(4) << endl;
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << *fcr + *pr << endl;
        try {
            *fc + *pr;
        }
        catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            *fcr + *pr;
        }
        catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << *fcr - 3 << endl;
        try {
            *fcr - -1;
        }
        catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            *fcr - 3;
        }
        catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << fcr->addFormeAt(*pr, 3) << endl;
        try {
            fcr->addFormeAt(*fc, -1);
        }
        catch (ExceptionForme & e) {
            cout << e << endl;
        }
        try {
            fcr->addFormeAt(*fc, 5);
        }
        catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << fcr->getAire() << endl;
        cout << fcr->translation(Vecteur2D(3, 3)) << endl;
        cout << fcr->translation(Vecteur2D(-3, -3)) << endl;
        cout << fcr->homothetie(Vecteur2D(-1,-1), 2) << endl;
        cout << fcr->homothetie(Vecteur2D(-1,-1), 0.5) << endl;
        try {
            fcr->homothetie(Vecteur2D(-1,-1), 0);
        } catch (ExceptionForme & e) {
            cout << e << endl;
        }
        cout << fcr->rotation(Vecteur2D(0,0), M_PI_2) << endl;
        cout << fcr->rotation(Vecteur2D(0,0), M_PI_4) << endl;
        cout << fcr->rotation(Vecteur2D(0,0), M_PI_4) << endl;
        cout << fcr->rotation(Vecteur2D(0,0), -M_PI) << endl;
        FormeSauvegarder sauvegarderfc("FormeComposee.txt");
        fcr->accept(sauvegarderfc);
        Forme * fcrprime = Forme::charger("FormeComposee.txt");
        cout << * fcrprime << endl;
        FormeDessiner formedessin;
        fcr->accept(formedessin);
        pr->accept(formedessin);
        tr->accept(formedessin);
        cr->accept(formedessin);
        sr->accept(formedessin);
        tr->setCouleur(Couleur::RED);
        tr->accept(formedessin);
        tr->setCouleur(Couleur::GREEN);
        tr->accept(formedessin);
        tr->setCouleur(Couleur::BLUE);
        tr->accept(formedessin);
        usleep(1000);
        delete fc; delete fc1; delete fcr; delete fcrprime;
        delete sr; delete cr; delete tr; delete pr;
        exit(0);
    }
    catch (const ExceptionForme & e) {
        cerr << e.getMessage() << endl;
    }
    catch (const exception & e) {
        cerr << e.what() << endl;
    }
}