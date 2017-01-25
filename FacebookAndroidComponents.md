## shimmer

1.

``` XML
android:theme="@android:style/Theme.Black.NoTitleBar">
```

```
<com.facebook.shimmer.ShimmerFrameLayout
    android:id="@+id/shimmer_view_container"
    android:layout_width="wrap_content"
    android:layout_height="wrap_content"
    >

    <LinearLayout
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:gravity="center"
        android:orientation="vertical"
        >

        <ImageView
            android:layout_width="64dp"
            android:layout_height="64dp"
            android:src="@drawable/fb_logo"/>

        <TextView
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:layout_marginTop="20dp"
            android:gravity="center"
            android:text="STRING!!!"
            style="@style/thin.white.large"/>
    </LinearLayout>

</com.facebook.shimmer.ShimmerFrameLayout>
```
