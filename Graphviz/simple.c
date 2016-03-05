//#include <gvc.h>
//
//int main(int argc, char **argv)
//{
//	Agraph_t *g;
//	Agnode_t *n, *m, *a, *b;
//	Agedge_t *e1, *e2, *e3;
//	GVC_t *gvc;
//	/* set up a graphviz context */
//	gvc = gvContext();
//	/* parse command line args - minimally argv[0] sets layout engine */
//	//gvParseArgs(gvc, argc, argv);
//	/* Create a simple digraph */
//	g = agopen("g", Agdirected, 0);
//	n = agnode(g, "11111111111111111111111111111111111111111111111111111111111111111111111111111", 1);
//	m = agnode(g, "22222222222222222222222222222222222222222222222222222222222222222222222222222", 1);
//	a = agnode(g, "33333333333333333333333333333333333333333333333333333333333333333333333333333", 1);
//	b = agnode(g, "44444444444444444444444444444444444444444444444444444444444444444444444444444", 1);
//	agedge(g, n, m, 0, 1);
//	agedge(g, n, a, 0, 1);
//	agedge(g, n, b, 0, 1);
//	/* Set an attribute - in this case one that affects the visible rendering */
//	agsafeset(n, "shape", "rect", "");
//	agsafeset(m, "shape", "rect", "");
//	agsafeset(a, "shape", "rect", "");
//	agsafeset(b, "shape", "rect", "");
//	/* Compute a layout using layout engine from command line args */
//	//gvLayoutJobs(gvc, g);
//	/* Write the graph according to -T and -o options */
//	//gvRenderJobs(gvc, g);
//	gvLayout(gvc, g, "dot");
//	gvRenderFilename(gvc, g, "png", "out.png");
//	/* Free layout data */
//	gvFreeLayout(gvc, g);
//	/* Free graph structures */
//	agclose(g);
//	/* close output file, free context, and return number of errors */
//	return (gvFreeContext(gvc));
//