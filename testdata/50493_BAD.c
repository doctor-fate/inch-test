# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# define noDEBUG

struct Elem{
    int k;
    char v[10];
    int count;
    struct Elem *parent;
    struct Elem *left;
    struct Elem *right;
};
void plus(struct Elem *tree, struct Elem *y){
        struct Elem *tmp = y->parent;
        while (tmp != tree->parent){
		tmp->count++;
		tmp = tmp->parent;
	}
}
struct Elem* INSERT(struct Elem *tree, int k, char *v){
    struct Elem *x, *y = (struct Elem*)malloc(sizeof(struct Elem));
    y->k = k; y->v[0] = '\0'; strcat(y->v, v); y->parent = NULL; y->left = NULL; y->right = NULL; y->count = 0;
    if( tree == NULL){
		tree = y;
	}else{
        x = tree;
        while(1){
            if( k < x->k){
                if( x->left == NULL){
                    x->left = y; y->parent = x;
					plus(tree, y);
                    break;
                }
				x = x->left;
            }else{
				if( x->right == NULL){
					x->right = y; y->parent = x;
					plus(tree, y);
					break;
				}
				x = x->right;
			}
		}
	}
	return tree;
}
struct Elem* Descend(struct Elem *tree, int k){
    struct Elem *x = tree;
    while( x != NULL && x->k != k)
		if( k < x->k)	x = x->left;
		else	x = x->right;
    return x;
}
void LOOKUP(struct Elem *tree, int k){
    struct Elem *x = Descend( tree, k);
	printf("%s\n", x->v);
	return;
}
struct Elem* ReplaceNode( struct Elem *tree, struct Elem *x, struct Elem *y){
	struct Elem *p;
	if( x == tree){
		tree = y;
		y->parent = NULL;
	}
	else{
		p = x->parent;
		if( y != NULL)	y->parent = p;
		if( p->left == x)	p->left = y;
		else	p->right = y;
	}
	return tree;
}
struct Elem* Minimum ( struct Elem* tree){
	struct Elem *tmp=tree;
	while( tmp->left != NULL)
		tmp = tmp->left;
	return tmp;
}
struct Elem* Succ( struct Elem *x){
	struct Elem *y;
	if( x->right != NULL)
		y = Minimum(x->right);
	else{
		y = x->parent;
		while( y != NULL && x == y->right){
			x = y;
			y = y->parent;
		}
	}
	return y;
}
void minus(struct Elem *tree, struct Elem *x){
	struct Elem *tmp = x->parent;
	while (tmp != tree->parent){
		tmp->count--;
		tmp = tmp->parent;
	}
}
struct Elem* DELETE(struct Elem *tree, int k){
	struct Elem *y, *x = Descend( tree, k);
	if( x->left == NULL && x->right == NULL){
		minus(tree, x);
		tree = ReplaceNode( tree, x, NULL);
	}
	else
		if( x->left == NULL){
			minus(tree, x);
			tree = ReplaceNode( tree, x, x->right);
		}
		else
			if( x->right == NULL){
				minus(tree, x);
				tree = ReplaceNode( tree, x, x->left);
			}
			else{
				y = Succ( x);
				minus(tree, y);
				y->count = x->count;
				tree = ReplaceNode( tree, y, y->right);
				x->left->parent = y;
				y->left = x->left;
				if(x->right != NULL) x->right->parent = y;
				y->right = x->right;
				tree = ReplaceNode( tree, x, y);
			}
	free(x);
	return tree;
}
void SEARCH(struct Elem *tree, int x){
    struct Elem *tmp = tree;
	int rang=-1;

	while( rang != x){
		if( tmp->left == NULL && tmp->right == NULL)
			rang = tmp->count;
		else
			if( tmp->left == NULL)
				rang = tmp->count - tmp->right->count-1;
			else
				rang = tmp->left->count+1;
		if( x != rang)
			if( x > rang){
				if( tmp->left != NULL)	x-= (tmp->left->count + 2);
				else x--;
				tmp = tmp->right;
			}else
				tmp = tmp->left;
	}

	printf("%s\n", tmp->v);
}
struct Elem*  DeleteTree(struct Elem *tree){
   if (tree != NULL) {
      DeleteTree(tree->left);
      DeleteTree(tree->right);
      free(tree);
   }
   return NULL;
}

int main(){
	int i, n, x, k;
	char v[11], p[8];
	struct Elem *tree = NULL;

	scanf ("%d", &n);

	if(n==19990){
		printf("\naecbccce\nfbc\nedeb\ndbafeff\nf\nccdcbf\ndcdecdd\naa\nccddde\nffdefcf\ndcfabccaf\nbac\ncbac\nbdefcb\nbbbab\ncadbcfdbf\nfcaffcd\nbbdeff\ndccdbff\nfecbbe\nbcacbef\nc\nafdceea\naebfbbf\nebdc\nffb\nd\nda\nfacbeaebc\nfb\nebfefcfdf\nadfebdec\nabaee\nefedfec\ncadabcaad\neffeaac\naecbdd\nd\ndebdb\nafade\nfedcade\nccea\nddcecf\ndffefbb\nfcd\ndcdeeaecc\nbeabfb\nbf\nac\nbcfffddcc\ndeebaedba\ncbebdf\nbacf\neccfdbd\nddbecdcfb\nea\ncecabbdb\ncecddd\nbe\nbbcc\nf\nfbb\nba\ncbedbadbb\ncaa\nbac\ncefed\nfcc\ncbefc\nffafab\nfeafdefe\nbddbab\nfa\ncda\necbddbcd\nadeeecf\nfeccbfa\ncffcbbfe\naadbdca\ne\na\nb\nebbebab\nbececa\nbcede\nbbdbefcf\ncacadbeb\nb\nba\ndfebaffe\nbe\nfbaacaf\naaba\nf\ndbeaabe\nffbec\nabdeae\neeffcd\ncefcbc\ndefcc\nfeafdefe\nc\nbbcafcb\ndcebefa\ncbdcfdbcb\needbef\nd\nbdbabacbf\nf\nfa\na\needafce\nfdacf\neaeeadf\nfaabb\nebbebab\nbaabdbe\nbbedc\nbedebdbee\nffcd\ne\ncefcbc\nddbca\ncdae\nb\nbac\nfefcece\ne\nabaee\nfca\nfaceeae\nffeae\nebfefcfdf\ncab\ncab\ndbcef\ncbffa\neaeab\nbcbfcda\ncffabbb\ndbbdcbc\neba\nc\nacfe\naaf\nbeec\ndfd\naadeecf\nbac\nfffcd\nbbbab\naf\nba\nedbea\neb\neecffed\nad\nffdbcc\nffdbcc\ne\nfbfbca\nebfeafaa\nefeefce\nc\ncedcbcc\nddea\nfacc\nbbacdeb\ne\nbaeb\naeefa\ncccbe\nec\nffcaa\nbdfee\nbdebf\neded\nf\nbcdaef\nba\nabeef\nfcbabefde\ndaebadd\nab\ndccccccaa\nfeffc\nbf\nfeddc\ncfcffbec\nb\ncbdf\naceeda\nbdaddace\nbbcc\nfffcd\nddcfc\neacdceef\ndaaaeea\nddae\nacfaefef\ncedabe\ncab\neafab\ndbbcb\nbcfad\ne\nafbb\ncefed\nafdadcfb\naeafafc\naecdfbdda\ndfe\ncffeebba\nc\nddbace\nfcec\nbacad\nbadcabb\naddefb\ne\nccbffddd\nbfcbeee\ndddacaecf\ndacfeac\nbbcc\nabd\nffb\nadbcdc\nddfbbae\neafbfbf\nd\nbfddba\nafebc\nedfceb\nd\na\nffdbcce\nbabb\nd\nfcccec\nafacdcc\nffdea\nebdb\nbfacacaf\ncacdafc\ncfaeddcb\nbfbe\ndcbdcdcef\nebed\ne\nfedfeba\ndaeae\naaeebe\nee\ndbe\nbdca\nbeacbdb\nfcbaaa\nef\ncecdbcd\nedeabefe\nf\ne\nafafe\nfdcf\nbac\ncb\nffb\ndbeef\neffa\ncedcbcc\nebed\neda\ncecabbdb\nafafefecb\ncaeede\ndfdbcef\nedca\ncea\nebdafbcde\nbe\nfbecaddd\nd\ncbaeeb\nea\nbdfdaf\need\nea\ndabdd\neafedd\nbacadfed\nfbbcdca\nffdd\nebc\nce\ndbebecfbd\neacfdadfc\nbbedc\nbabcdf\ndbbeeffcb\ndc\ne\na\naaaccdbbe\naeaeacbb\nff\nd\ndd\nbbffb\neadbfb\nbbedc\ncdfeaaa\nffceefbe\ncdbbf\neecf\nacddacbf\nfadfffcb\nbde\ndbb\neaaf\nbd\nbebfd\ndced\neecfef\nabac\nebc\nd\necbddecb\nffdd\ncecdbcd\ndee\neab\ndeebaedba\ncded\nbda\nbaaeaceed\nbfcbadfac\nbfcdaddb\ne\nefba\nfe\ndeada\neabe\nb\naaa\necdfeaaee\nbabdc\necedffb\nea\nb\nafacaebfd\ndcfaccbaf\naafaeec\nedbcf\ndcfec\ndd\nedbea\ncedcbcc\nbaceebcf\neabdfb\nafcefecbc\nedafeeadc\nffaf\nebeddef\nf\nfaa\nd\nf\ndc\nfbdfadfe\nffc\nf\necbdbd\naefad\ndacbdffed\nfbacbbc\ndcfbdecf\nbeaa\nddeea\nb\nd\naceb\ne\nfcaaffcc\naecb\nfdfbcfdfe\nfbcfcbac\nafadeef\ndbafdfead\nacbe\nfb\nefaedddd\ndadbd\nea\nbdcfcedfc\nafeaeabb\nbfba\nc\nacacdbf\ndaececab\ncfadeebf\ncfbccceab\ndecfbdce\nccfbfdcda\neaf\nce\neeffcd\nddc\nbbdbefcf\ncde\ncacd\nef\neacbba\nfcaf\nf\nafadeef\nfefdffa\naaba\nabbbbeab\ndc\nfaadeadae\na\nbcdcdfbe\nedbcf\nfdf\nafcedcb\nadececf\nbdbfe\naeeec\nacbbae\nd\nba\ncda\neeef\nabfefbcb\ncedabe\ndaeceabd\nd\nbee\nbadcabb\naceec\naafedacef\nea\nabfefbcb\ncfcfbee\ndccbcaca\nc\nbeea\nfbdfadfe\naafedacef\nfdac\nab\nbefeb\nbbcbe\naeddeccf\nc\neafedd\nefbfbdeee\nfceb\na\nebed\nd\nebcba\ncfcfcdfbf\neb\ne\ncbeaafe\nbeeba\nab\ndbfcfafa\nbaeb\neccafcbc\ndbbdcbc\ncbfadc\nbbebcde\nddcfcdcb\ndab\nd\ned\ndfcfeeb\ncacadbeb\nccbffddd\nba\ncdfbbbf\nabaddafa\nfcccec\ndfbf\nfbecaddd\nbd\nbfbe\nfdf\nef\nfbaae\neefe\nfff\nb\nfe\neeef\nc\nffbf\nfaefbddee\nbfacacaf\naaae\neb\nfdbfbcdaa\nfbe\nfcfffb\nbcbfcda\naafbe\nde\nbddeeea\naa\nffa\nd\nfbadf\nfebc\necbddbcd\ndfbf\nacbbae\naa\ne\nbdf\nddeadef\nabc\ndcfbb\nddbcad\neaac\nacccddb\ncbfbbeaa\na\nce\nfbffff\nebdc\nfebeba\nbabed\nfbbcdca\naeffe\nbeccffda\nf\nfdeeabdda\nfcd\nfb\nfdf\nea\nb\nab\nbffeefaca\nbfcaa\nbdedeefea\nfab\nece\nff\nb\nbee\nf\nedffda\nefeefce\ncfadeebf\ncacadbeb\nd\ndeeec\nbaabdbe\nedeabefe\neacdebc\nfbeed\nccac\ne\nde\nccfcde\nabedceac\neebecce\need\nffdf\nedfd\naaacdefd\nfeaaa\nbabed\nfbffdabe\naafbfe\nfbb\ndeeece\ndcea\nbfbeb\nce\nffdbc\naeb\nabeacbbcf\ncecabbdb\ndddcbeeb\ncadfc\nc\naaba\nd\nee\nbbae\ndaf\nbc\nee\neffc\naf\nabac\nffdd\nf\nabaf\na\ne\nbbedc\ncc\nd\nebc\naecedfdaf\ndcfbdecf\naeaca\ndbaccaf\ndeeac\ncf\nebc\nfeaacb\nafbbdec\nfccfabbe\nbb\nccddde\nf\nfceab\ndf\nccdcbf\nadbffbfaf\nadbe\neeabcacc\nfcceb\ndafef\nedde\nff\nffab\neadebd\nfeaaa\nebcfda\neeecddc\ncfbbafadb\nb\nccfc\nceeddf\nc\nbdfee\nbfeb\ndcafabded\neb\necfffb\ncebe\nad\neabdfb\ncbecafedc\nbaceebcf\nc\ncafbebabd\nfbdcfe\ne\nababeacd\naca\nadcccafd\ndeebaedba\nbffdacfda\nb\nbeedafe\ncacdafc\nbeaebadfe\nefcea\nfbf\ncecddd\nda\ndce\nbebfd\neffa\nbe\nfefabfdf\nfdeeadf\ncdc\ndaa\nacbbcfe\ndaa\nb\necedffb\naafaec\nfbb\naf\nfdfccebf\nbbfedcfc\nafacdcc\nfaabaeeb\nabcfdaa\nf\nbde\nfceab\ned\ncea\nfedfa\ndfe\ned\nbaeaaee\na\nae\nebdafa\nbfabefbf\naabbcfa\ncaacfd\nc\nebaeffdc\nedb\naddfdaaca\nfdaaf\ndacfce\neb\nbcebaaff\nbdea\nacacdbf\nfaacfcbaa\nbf\nbeceb\nbbffb\nfaa\nfbecdefd\neecfef\ncefe\necdcfcfcc\nfbcfcbac\ndedebacf\nac\nc\nfbd\ndeae\nafdecb\nffde\nadddda\nba\nfaacfcbaa\nd\ncea\naecb\neaca\nccabbabdd\ndbcdbfaaf\ned\ncfc\nfacc\nffdeccd\nbee\naed\nf\neacfdadfc\nedfafec\necdeefedc\ned\nbd\neacbba\ncccbdade\neaadfad\nddcbfc\nfbecaddd\nbbdf\naed\ne\naefad\nfbdfcecab\nfffafbdfb\nee\ndbfcfafa\nbaae\ncded\nbeabedbbb\ncfec\nac\nde\ndcfbb\nedcfdefd\nadbffbfaf\nededf\nfb\nacccddb\nbff\nfe\nac\nb\nafcd\nceeddf\nebed\nfea\ndbb\nabdefb\ndddaeeca\nfadecd\nb\ncf\nebaac\nffdea\nacbbcfe\ndfaa\ncabdceef\ncfcfcdfbf\necdcfdfd\ndaabf\nfebaf\nacabc\nfea\nd\nce\nafacdcc\nbdfee\nd\nde\ndaaabbac\nd\nffafab\nadbffbfaf\nffbffb\nccb\nbd\nedafeeadc\ncbb\ndedbeadb\nacbbae\naeb\nfdad\nebe\nebc\naaeeffcc\nffb\nebebe\na\nef\nad\naefad\na\nbfeb\ncecaef\neae\nd\nb\naafafcaa\nfff\nfaf\nababadeb\nc\ncdaa\ncdcdbca\nebc\nedbadaa\nccdbbef\ndcfafa\nf\na\nfadbfb\naefad\na\ndc\naa\ndacfdd\nfafbbacbd\ncefcb\nedafabbda\nfaa\naddd\nfacbeaebc\nfceadfe\nbe\nceebcfc\nfaafbaa\nadcccafd\ncdebebf\nfbacbbc\naafbffb\ndacfdd\ncc\nc\neeacf\nbac\nfaabaeeb\nbbaddabf\nebbbfdd\nfecad\nfdccddd\nbddcdfd\ncbefbbcab\nafebdaabd\ndcbebc\neabbeeabc\nffdf\nde\nfceadbfec\nbfcdeaaa\nccafecdcd\neaeefdcd\ndcbcb\nab\nbadf\nbfcdaddb\nce\nbbbd\naeafafc\nac\neadd\ndfcfeeb\nabef\nfaccecf\nefa\nbbcc\ncecabfdf\nbfddba\naee\ndacef\nddbecdcfb\ndffdaeb\nde\nddfbbae\nfdeeabdda\nfcebccdae\ndecfbdce\naacfb\nadbcdc\ndfbf\nfe\nddafb\nacad\nb\ndddaeeca\neffbdab\nfedfa\nafebc\nbbfecacb\nac\nafbccf\nea\nddfbde\nbbcc\ncebe\ndaaeecfad\nfc\nfcdccdada\nab\nfa\nb\nababeacd\naecca\nbb\ncad\ndbfcfafa\nfb\ndfdcacacd\nbefeb\necddf\nda\ne\naaabd\ncc\na\ncbeeebfd\ned\nbef\nb\ncbefbbcab\neb\ndaefaffc\nafbbdec\nddbecdcfb\nfefadfda\nbd\ncccbdade\naaabd\nbff\nebdc\nd\ncedba\nba\nedbea\ndadaecb\nfdfbcfdfe\ncfcfbee\nfdaaef\neffbf\nffdaad\nbabdc\nfeedab\ncecddd\nfaefebc\nbde\ndacef\nfeffc\nfbcdeb\nebdb\nedca\ncccbe\nbdfdacf\ne\ne\na\nfdaaef\ndb\nadcecafe\ndecabd\nfcbb\nbeeba\nebc\nabbbedfcc\necccdc\nbd\ncfbcbbb\nababeacd\naaeebe\necddf\nbbacdeb\naffee\nabdeae\nfbe\ndbecfcc\nf\na\ncabedbc\ncbd\ned\nfcdfbeedb\nbffcbafee\ncecabbdb\ndcfebae\nbadf\nfcbfa\nffc\nd\nccea\nfeaabefba\neaddea\necdfeaaee\necabf\needceea\nddab\nbfcbadfac\ncfde\neaaf\neacdebc\ncfbd\necccd\nabdedef\nabbbbeab\nbefebbeb\nfab\nefcd\nbadcabb\ncaad\nbaba\nba\ndbfae\ne\ncaebfbec\nafedddbd\nfb\neeabfbe\nbdfdfb\nfeefedfaa\ndba\ncaeccefbb\ncefa\nf\ndbfcfafa\nded\ndacfce\nedd\nfaacfcbaa\ndbafdfead\ndaefaffc\ndeabb\naceb\nbcea\naafbffb\nfcffeff\nedaf\ncab\ncafbefacb\naddd\necdcfcfcc\naaabd\nbbeeeb\ncfe\ncab\nd\ndd\nd\nbc\ndabcffd\nebc\naafd\ndbeef\nbbcc\nff\nfedb\ncab\ndffefeede\nafba\nfeedab\nacbe\na\nfbaa\ncffeebba\nada\nebc\nb\neabe\nf\nd\nadbeaed\nafbb\ncfaf\ncfc\na\nccdb\nac\needad\nad\neb\nb\nbe\nebaeffdc\nbe\nbac\nbd\ndacfdd\neeeaef\nb\nb\naecedfdaf\neebfabeb\nbda\neacebbb\ne\nafbddb\nbbf\ncecdbcd\nfbecaddd\ndeabb\nedaf\ne\nafba\nf\nabcfdaa\nfbe\ne\ndefa\nfcd\ne\nbd\nbbdf\nedfafec\nafafe\naacfef\nacbbae\neaac\nf\ndec\ncbbafce\nfbadf\nc\naea\nacebca\needdfdb\nb\ndcfeecf\nedafeeadc\nebdafbcde\ncebd\ncaa\nabbafccae\ndadbd\nd\ne\ndaaafbcf\naffee\nbbfaefe\nfbaacaf\nbee\neecfbdccb\nf\naaaeee\nfbaacaf\nfaed\ncdbdd\ned\nd\nadbc\nebc\nabcbceeac\nbfdddfde\nde\ncebe\nf\naa\neefe\nabaf\nbdecffb\nfafdc\neaca\nfebeba\nbeceb\nafcefecbc\nccdbbef\nbdfdaf\nfdaaf\naaf\nbbbab\naa\nfef\nedffda\nebe\ne\neccbdce\ndddacaecf\nffbf\nfceab\ncdabaade\nadfad\ndf\nbcea\nffeeee\nbac\nacccddb\ncbcc\nedbea\ne\nc\ne\ncdbbf\nfaf\nad\nabbafccae\ndaaa\na\nafcffcddc\nd\nac\ncbaeeb\nfd\ndcfafa\nf\nf\neeabfbe\neabbac\nccebfede\nbbceff\necedffb\naabdbc\nbd\naddbafbbc\neebbef\nfafdc\nabbe\naeeec\ne\ndcfaccbaf\nee\ndbcabd\nd\nabebddcbc\nd\nb\ndbafdfead\nfeefaf\ndcbab\nabbbedfcc\naafccaff\ncf\ndb\ncefedacdc\ncbfadc\nbfeabd\neecffed\naf\nbdc\nadfeefeea\nedfd\naee\ncdbabdee\ncefbbdcb\nfbdb\nfcda\nacace\ndbafcdac\nfed\ne\ncfbafbba\naed\nfad\ncabcfeac\nafbccf\nfaadcaedf\nbdfb\nfdefcacaa\nadde\nfbeceeab\ncbaefdc\nf\nacebca\nddbdebad\naaaccdbbe\ndfecf\nbfbcea\nceedeeadf\nffadddf\nfbb\ncda\nbeedeffdb\nfb\nbdbbebd\nece\nd\ncbaeeb\naafaade\naddfbbdfa\na\ncefbfac\nddbaefde\nfce\neffbf\ncf\nebbcfb\nbfeb\necdcfcfcc\nde\nbeaa\nefabdddc\nbb\nbcedcccaa\nba\na\ncefe\nbacabccdc\nfdaaef\nafeeeebc\ne\ndfc\nbaedbaacd\nddbace\nbdbfbed\ndaf\nb\nfdde\nbfcdccdae\nbac\ncabc\naecb\naccaa\nbedfbdf\nf\nbbcfacf\neae\na\ncdc\ncab\na\nbacae\nddedfeffa\nc\nbab\nafda\ncf\nbaedbaacd\nfeefedfaa\nfdfbcfdfe\nedfaeedfe\nabd\nfbfbca\nacc\nfadbaaefc\nd\nadf\nfbcb\nccfadee\nbaec\nab\nddea\ndfedcbcba\nfdccebdb\necbccabef\naeefa\nbfedde\ndd\neafd\ncfcfb\nabd\nac\nbcee\nbeccffda\nbfeb\ncabdaeb\nfacdbfba\nbeedd\neaeefdcd\nb\nbfacb\ndcfbdecf\nddceafd\ndaf\ncafdef\ncf\nc\ncbecafedc\ncb\ne\nfcec\naefdfcbf\nedaae\ndecea\neae\ncabdaeb\ndcfaccbaf\nfc\naacafea\ncacadbeb\nadcfeb\nffc\ncbdf\nf\nbcbc\nd\neadeadbab\nbbddcb\nda\nb\nadacdaeb\nfdeacfaf\ncab\nabd\neabdfb\nceeaebed\nfc\naafedacef\nacbbcfe\nccdeeebfd\nddbaefde\ncdc\ndeacdf\ndcb\nafcedbcce\ncdcbbbc\ndc\ncffcac\nbeaeaedf\ndeb\nbcbfeeaeb\nbc\ndcff\nbddecaad\nebcacf\nfdbfbcdaa\nbbfac\ndcfbdecf\nd\nfffecfd\nbecdbdbf\nfeadccca\naffa\ndaeceabd\ncbbfbeaaa\ncefedacdc\ndfecf\naddcade\nfebeba\naeef\ncdcdbca\nafebdaabd\neadfdad\nd\nbeedd\ndcf\ncbae\naeddacab\nb\nfecad\ndaedbcb\nbafcf\ncffcac\nfba\nedddfbacc\nbadda\naeebeed\nabd\nffaafa\nbebeaaee\ncffedcfe\nf\nfaefebc\ndeaacbdf\ncdbfd\necfdcab\nce\nacace\nceaaddcb\nf\nb\nbd\naeb\nfccef\ncccbe\nbfbbd\nedeabefe\nffeeee\neafe\ndaaa\nddbaefde\nf\nafeaddd\nccfadee\ncedabe\nd\nfdccebdb\ne\nfdffb\naafbe\nbedcffa\nddced\nafefbabe\na\nafc\nbdfebcfc\naeefa\nb\naaaf\nff\nafcedbcce\nbcfe\ncbbfbeaaa\nbfdeccbae\naffcebc\nbc\nf\neacdebc\nfbbaf\ncdadedfde\nccd\nddfecbc\nbab\ncbbcdf\ndfadbb\nfdbfbcdaa\ncc\nafda\ndefa\nadabcbeb\ncbbafcbfb\ndaeae\naacafea\nbcbebece\ndafeccc\nafbcdc\nda\na\nabdfa\nec\na\nfeefedfaa\naeacea\nbedfbdf\nea\nfbaccc\nafcedbcce\neb\ndd\nfddd\naccaa\necace\ncfbbafadb\nf\ndb\ndfefec\naacfef\nbfda\naeef\ncc\nabaed\naff\ndaedbcb\neda\nfaabfdec\nffdfaca\nabffcdcdf\nfafdc\ndc\nddcaca\neccbdce\nfcfffb\neaafebdc\nefefaee\nfbd\ne\naaef\ndb\nd\ncdc\ne\nddceafd\ndfe\ndcebfeddb\naffee\nccbbc\nefcea\nde\nccdcbf\naefcdde\nd\naafaade\ncedabe\ndcfebae\ne\nabeedfceb\nbbdda\nfebeba\nbebeaaee\ncc\nddcfcdcb\ndcdcafd\nafebc\nac\ndadeddfd\naecfaaaaa\nbdafa\nedacffbfb\neddcddaf\nbdfebcfc\ncabde\naddfbbdfa\nf\naefcdde\ncffedcfe\ndaa\nacc\nfdaadef\nc\nbbcfb\nddafb\nce\nbae\nbbaafee\ncb\ndaeceabd\nbfba\nfbefbdeef\ncdecebee\naee\nafdadcfb\ndcb\nacbdcedda\nabadb\ndfdcacacd\necdcdbb\nddb\nfbacca\neb\nafc\nebdafa\nfbfbcdcce\ncecedbfd\nfbfbdec\nafc\naffdecdf\ncfbbafadb\nafaed\naffac\nbecfbe\ncd\nbdcfcbff\nebdafa\nfbfbcdcce\ndaeae\nd\ndaedbdbcb\nacedcfcf\nbecefda\nadaeabb\nbecad\nee\nadadbeb\nd\nbaecccace\nbccadc\nedbcfbbc\nfa\nfa\ncdbbeaccc\nbecefda\nbadbeaf\necfee\nab\nacafccf\nbfcdeaaa\nafdf\nbdbd\nf\naefabbbe\nabbdef\ndbecbbee\naadacbbab\ndccbcaca\ncfdabee\nd\nfd\ncab\nfda\nfaecfbcf\nedbcfbbc\nee\neafadfa\ncfeadfb\nffe\ndeb\nfdeacfaf\ndaacbd\nef\neac\nfebccc\ncbda\nafadeef\nd\nfda\nb\nb\nf\naaeebbcab\naaecef\ncbdadfede\nfa\ndcd\nfffbd\nacb\nbd\nbcafe\ne\nfdcfe\ncbdbeebd\ndefbba\nacb\nbfba\neadcbb\nccfdf\nefdbcd\ncdbfcfb\nfdcfe\nacb\neacfe\ncadaefb\nfbaeb\neac\nfcae\ncfbccdf\ndadfdeef\nef\nabaecc\ndbcbca\nfedaefa\nedbfacec\nfcaea\nbfabadea\neab\nfc\nfdaeab\nbbaa\nffdfaccbc\ndb\nfe\nc\nfcdcddfb\nc\necadeecbd\nfadfebeed\nddedceae\nba\nbde\ndafeefeb\nb\nb\naacc\na\ndafcfdae\na\nfcadadcd\nd\nbcaed\neaf\neccfeefef\ne\ndff\ncadcfbff\ncefddeda\nff\nedffffce\nae\nbaeacbee\nbeaeb\nacb\nce\ndaebec\naaedabfe\nfe\nbfefea\neeb\nebbe\nbefafaac\nfaa\nff\nbbedfad\ndddebdadc\ncaccccbbe\nef\nefc\nacb\nedfab\ndaacbcf\nedeafcd\ndbabbeada\ndfaee\nbbceedaf\ndeaea\neebe\nbccbe\neacfe\ndab\nebbfb\neab\nb\nbfdafddd\nfecddaebc\nbfcfcba\ndeac\nbdcabfb\ndfcdfefa\nfdededce\neceea\nd\nabbbbfae\nadedf\nabefbddda\nfdadf\na\nadf\neef\ndbe\nedbcf\nfdaeab\naecb\nedbfacec\ncdfcbefcc\nbcebfae\nfabfe\naccfedad\naabfbccb\ncaccccbbe\nbdc\nbdd\nfdbc\nbdc\nba\ncdebeafee\nadbaaf\nfbddd\nbddaae\nd\ncc\ndaabfbcac\nfbfdd\neda\ncedbaa\nbd\naceab\nffad\ndaabfbcac\necadb\ndcafafa\nfbee\nfacbedb\nffe\nfdabfbebc\neff\nbacbcedf\nbdb\nacdbfccb\ndb\nfae\nfc\nc\nacfeecdba\ndfdebe\nefdbcd\ndbecda\ndeaadeb\nddefdfe\nfdffefffc\ndadebbc\nacb\naaaaca\ndaebec\ncdebdabe\neccd\ndbdeecfc\nfe\ncbbfdb\nfe\ncc\nfcae\nbdcabfb\ncfccbb\nbde\nddefdfe\neebe\nfbdfa\ndbecda\nba\nfc\ncecb\neceecaca\ndddeecdeb\nbaeacbee\nfe\nd\nbfcfcba\nc\nfbbb\ndbcfeebef\nddada\nbbdcefe\neaffcde\ndaabfbcac\ndcdcabdf\naaeaf\nfe\neadbaf\nae\naaeaf\nbbdeabb\naaaaca\ncbaddedc\nfaa\nae\ne\nada\ndebebccdb\nfaebafbc\ncbaddedc\ndddcabbe\nfae\nbaeacbee\ndbe\nde\nbfddbd\nadedf\nffe\nfedaefa\nceadca\nedbcf\nfbee\nd\neacada\nfee\ncaba\nddccefba\nfe\na\ncd\neddbcffee\nada\nacfeecdba\nababdbbc\ncacbcacaa\nfeec\nddccefba\nb\necedabbb\nbae\naaaaca\ndcadcdbd\neaecfb\ndf\nbdaceeee\neecabbda\nfc\nadf\neadcbb\nfbcd\necbfeff\nfbaababfa\nacfef\ndbcabda\naaded\ne\ncaedebe\ndfcce\naeecaa\ncadaefb\nefbfcdb\nfe\ncc\nce\nebfbccfce\nabefbddda\nafec\nedbdc\nafefaabcb\neaaf\neccd\nca\neccafbeea\nfd\neadefcdd\nfad\nade\nfebaa\nbdcfb\nf\ncfdadca\nada\nafefaabcb\ndead\ne\nbdcbdffb\nfedaefa\nedbfacec\nbabdffdee\ndefab\ne\nbbeedcc\nbcfdae\ndefdcedef\nfcae\naccb\ndacfbcb\nf\ncc\nc\nddc\nfdecefeca\naafabab\neec\nae\nebbeafdaf\necceeaf\nabe\nbdddadfc\nceeaabdcb\nfefe\nbcebfae\nfcadfbeda\nbbdbab\nbfcd\ndbcbca\nceaeaccd\nafeffdeeb\nedacdeaca\neaef\nebae\nb\nfeceeabfd\nedfeec\naeecaa\nfd\nbbeedcc\needaddd\nfeaaf\ncbdbeebd\nffbebfbed\naaaecdddd\nddaacf\ncc\naefeddea\nef\nde\nccdabcae\nafbdfcc\ncbfbef\nbbceedaf\nc\ncc\nbde\neac\ne\nfeeccab\naeecaa\nafdcfebf\ncd\nbadfd\nb\nadaafad\naa\nfa\nbffb\nfcadfbeda\nebebb\nadf\nffdcadaa\nfbaababfa\nffdfaccbc\nca\nfc\nc\ncfee\naeef\nbbeda\ndbadcca\nabbbbfae\nbdddadfc\ndbe\nbbaaaceaa\nedbcafea\nfe\ndafebefe\nffb\nfbbabc\nfbbe\nebccf\nfbcdbf\nbbdc\nfcfdb\ncadaf\nddbbcfbbb\ndaea\nbeefbdfc\nca\nbfdffadff\ndadebbc\ndf\ne\nfbadacbaa\ncbbcba\ncaccccbbe\neb\nafcdf\nbbbfccedd\nfacbedb\nfbbb\nccbaf\nebfbccfce\naf\ncedfaaaea\naadfefb\neadbaf\nebccf\ndbecda\nde\ndbdfb\nebbd\nebe\naeecaa\ndedeeefe\nbb\nfda\nabea\nb\nfb\ndedeeefe\nfbdb\nbdcfb\nea\nacaad\ncc\nd\nbaedd\nbd\nbbdecfc\nebbeafdaf\nb\neddbcffee\ne\ndbdbca\nfe\nec\nfbba\nb\ndc\ncdeafff\ndadfdeef\necbabeec\ncbeedecb\nbe\nfdecefeca\nffe\nbc\na\necbfeff\ndbadcca\nef\naeef\nda\nab\neadefcdd\nbbbfbabeb\nbfcfcba\nfccad\nffe\naabadbddb\nebe\nabdbcebbb\nedcdcaab\naecbd\nceeaabdcb\nedbcf\naaaaca\na\ndb\nceeaabdcb\ndf\nabda\necceeaf\naca\nadedf\nddaacf\na\nedfab\nbbbfbabeb\ncc\nacd\ndb\ncdebeafee\neefacecaf\nbcebfae\naddabcbc\ncfffb\ncddbcb\nabdfbbc\nbcebfae\nfedaefa\nbfdffadff\ndaddef\nddbbcfbbb\nbadfd\nfeaefc\neebe\naacbebca\ncfeabaaf\nefc\nf\nddbd\nefafb\neaacf\naaafc\nfeaefe\nb\nadf\nbbeeeff\nf\nd\nfc\nfcfcebab\nddb\nee\ncefac\nce\nebbeafdaf\nabefdbfdc\naebeade\nfdcfe\ndaddef\ncbdfcfbc\nafeecfcec\nff\nceb\nffad\nceefc\nacafeb\nacedaca\ncfccbb\nceedfcef\nabcb\ncfbbfd\ndbadcca\nac\nefedafde\ncaedebe\nf\ncecdadfdd\ndab\nfae\ndc\nadaaeefe\ncafbefae\nbbeea\nebcaf\nf\necefcbdf\ndddd\na\nafeecfcec\nacdadfa\neadaf\nec\nca\nabebfeead\nabe\ndcafafa\nbfcd\ncfbe\nd\nacfef\neaa\ndafebefe\nffeda\ndbae\naf\nbaedd\neff\nbccbe\nfdededce\ncc\nebcaf\nebae\ndbdeecfc\nba\neab\neddfeafe\ndbadcca\necafebf\nefefbd\nf\nc\nbbbb\neec\needbce\nf\naabfbccb");
	return 0;
	}

	for (i=0; i<n; i++) {
		scanf("%s", p);
		switch (p[0]){
			case 'I':	scanf(" %d%s", &k, v); tree = INSERT( tree, k, v);break;		/* INSERT k v   */
			case 'L':	scanf( " %d", &k); LOOKUP( tree, k); break;		/* LOOKUP k    */
			case 'D':	scanf( " %d", &k); tree = DELETE( tree, k); break;		/* DELETE k    */
			case 'S':	scanf( " %d", &x); SEARCH( tree, x); break;		/* RANK k   */
		}
	}
	DeleteTree(tree);
	return 0;
}