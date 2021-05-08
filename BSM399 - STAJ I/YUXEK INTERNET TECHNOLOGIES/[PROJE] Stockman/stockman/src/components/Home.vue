<template>
  <div>
    <h1>Stock-Man uygulamasına hoşgeldiniz!</h1>
    <br />
    <h6>Verilerinizi istediğiniz zaman yedekleyebilirsiniz ya da yedekten geri yükleyebilirisiniz.</h6>
    <h6>"Günü Tamamla" butonuna tıklayarak yeni bir güne başlayabilirsiniz.</h6>
    <hr />
    <p>Güncel Bakiyeniz: {{ funds | currency }}</p>
  </div>
</template>

<script>
export default {
  computed: {
    funds() {
      return this.$store.getters.funds;
    }
  }
};
</script>