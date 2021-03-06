#if WITH_BIAS
bias_v = zq_mm_load_ps(bias + out_c);
a0 = zq_mm_add_ps(bias_v, zq_mm_load_ps(dst_ptr0));
a1 = zq_mm_add_ps(bias_v, zq_mm_load_ps(dst_ptr1));
a2 = zq_mm_add_ps(bias_v, zq_mm_load_ps(dst_ptr2));
a3 = zq_mm_add_ps(bias_v, zq_mm_load_ps(dst_ptr3));
a4 = zq_mm_add_ps(bias_v, zq_mm_load_ps(dst_ptr4));
a5 = zq_mm_add_ps(bias_v, zq_mm_load_ps(dst_ptr5));
#if WITH_PRELU
slope_v = zq_mm_load_ps(slope + out_c);
c00 = zq_mm_min_ps(a0, zero_v);
c01 = zq_mm_min_ps(a1, zero_v);
c02 = zq_mm_min_ps(a2, zero_v);
c03 = zq_mm_min_ps(a3, zero_v);
c04 = zq_mm_min_ps(a4, zero_v);
c05 = zq_mm_min_ps(a5, zero_v);
c10 = zq_mm_max_ps(a0, zero_v);
c11 = zq_mm_max_ps(a1, zero_v);
c12 = zq_mm_max_ps(a2, zero_v);
c13 = zq_mm_max_ps(a3, zero_v);
c14 = zq_mm_max_ps(a4, zero_v);
c15 = zq_mm_max_ps(a5, zero_v);
a0 = zq_mm_fmadd_ps(slope_v, c00, c10);
a1 = zq_mm_fmadd_ps(slope_v, c01, c11);
a2 = zq_mm_fmadd_ps(slope_v, c02, c12);
a3 = zq_mm_fmadd_ps(slope_v, c03, c13);
a4 = zq_mm_fmadd_ps(slope_v, c04, c14);
a5 = zq_mm_fmadd_ps(slope_v, c05, c15);
#endif
zq_mm_store_ps(dst_ptr0, a0);
zq_mm_store_ps(dst_ptr1, a1);
zq_mm_store_ps(dst_ptr2, a2);
zq_mm_store_ps(dst_ptr3, a3);
zq_mm_store_ps(dst_ptr4, a4);
zq_mm_store_ps(dst_ptr5, a5);
#else
#if WITH_PRELU
slope_v = zq_mm_load_ps(slope + out_c);
a0 = zq_mm_load_ps(dst_ptr0);
a1 = zq_mm_load_ps(dst_ptr1);
a2 = zq_mm_load_ps(dst_ptr2);
a3 = zq_mm_load_ps(dst_ptr3);
a4 = zq_mm_load_ps(dst_ptr4);
a5 = zq_mm_load_ps(dst_ptr5);
c00 = zq_mm_min_ps(a0, zero_v);
c01 = zq_mm_min_ps(a1, zero_v);
c02 = zq_mm_min_ps(a2, zero_v);
c03 = zq_mm_min_ps(a3, zero_v);
c04 = zq_mm_min_ps(a4, zero_v);
c05 = zq_mm_min_ps(a5, zero_v);
c10 = zq_mm_max_ps(a0, zero_v);
c11 = zq_mm_max_ps(a1, zero_v);
c12 = zq_mm_max_ps(a2, zero_v);
c13 = zq_mm_max_ps(a3, zero_v);
c14 = zq_mm_max_ps(a4, zero_v);
c15 = zq_mm_max_ps(a5, zero_v);
zq_mm_store_ps(dst_ptr0, zq_mm_fmadd_ps(slope_v, c00, c10));
zq_mm_store_ps(dst_ptr1, zq_mm_fmadd_ps(slope_v, c01, c11));
zq_mm_store_ps(dst_ptr2, zq_mm_fmadd_ps(slope_v, c02, c12));
zq_mm_store_ps(dst_ptr3, zq_mm_fmadd_ps(slope_v, c03, c13));
zq_mm_store_ps(dst_ptr4, zq_mm_fmadd_ps(slope_v, c04, c14));
zq_mm_store_ps(dst_ptr5, zq_mm_fmadd_ps(slope_v, c05, c15));
#endif
#endif