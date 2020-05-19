#include "mex.h"
#include "src/voro++.hh"

using namespace voro;

/* Input Arguments */
#define L_IN    prhs[0]
#define	M_IN	prhs[1]
#define	S_IN	prhs[2]

/* Output Arguments */

#define	M_OUT	plhs[0]

#if !defined(MAX)
#define	MAX(A, B)	((A) > (B) ? (A) : (B))
#endif

#if !defined(MIN)
#define	MIN(A, B)	((A) < (B) ? (A) : (B))
#endif

double x_min = 0, x_max = 75;
double y_min = 0, y_max = 75;
double z_min = 0, z_max = 0;

const int n_x = 6, n_y = 6, n_z = 6;

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	/*
	*/

	double *m_out;
	double *m_in;
	double *l_in;
	char *p_in;
	size_t m, n;
	size_t m_s, n_s;

	m = mxGetM(M_IN);

	n = mxGetN(M_IN);

	plhs[0] = mxCreateDoubleMatrix((mwSize)m, (mwSize)n, mxREAL);

	l_in = mxGetPr(L_IN);

	p_in = mxArrayToString(S_IN);

	m_s = mxGetM(S_IN);

	n_s = mxGetN(S_IN);

	mexPrintf("%s\n", p_in);

	mexPrintf("%p\n", &p_in);

	mexPrintf("%s\n", p_in+1);

	char **p;

	p = &p_in;

	mexPrintf("%s\n", *p);
	
	mexPrintf("%p\n", p);

	//mexPrintf("%s\n", *(p+1));

	m_out = mxGetPr(M_OUT);

	m_in = mxGetPr(M_IN);

	x_min = l_in[0];
	x_max = l_in[1];
	y_min = l_in[2];
	y_max = l_in[3];
	z_min = l_in[4];
	z_max = l_in[5];

	container_poly conp(x_min, x_max, y_min, y_max, z_min, z_max, n_x, n_y, n_z,
		false, false, false, 8);

	double x, y, z, r;
	//mexPrintf("%d_%d\n", m, n);

	/*
	for (int i = 0; i < m*n;i++) {
		mexPrintf("%g\n", m_in[i]);
		m_out[i] = m_in[i];
	}
	*/

	for (int i = 0; i < n; i++) {
		x = m_in[i*m + 1];
		y = m_in[i*m + 2];
		z = m_in[i*m + 3];
		r = m_in[i*m + 4];
		//mexPrintf("%d_%d_%d_%d_%d\n", i, x, y, z, r);
		conp.put(i, x, y, z, r);
	}

	

	conp.draw_cells_gnuplot("test_poly.gnu");
	conp.draw_cells_pov("test_poly_v.pov");
	conp.draw_particles_pov("test_poly_p.pov");

	conp.print_custom("ID=%i, pos=(%x,%y,%z), vertices=%w, edges=%g, faces=%s","packing1.txt");
	conp.print_custom("%i %q %s %a %t %l %n", "cell.txt");
	conp.print_custom("%i %q %v %c", "packing3.txt");
	conp.print_custom("%i,%x,%y,%z,%r", "particles.txt");
	conp.print_custom("%t,%P,%n", "planes.txt");
	//conp.print_custom("%P", "vertices.txt");
	//conp.print_custom("%n", "neighbor_v_f.txt");



	return;

}