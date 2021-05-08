using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using WebUI.Models.Data;

namespace WebUI.Controllers
{
    public class AdminController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        #region // Slider

        public ActionResult Slider()
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                var slider = context.Slider.ToList();
                return View(slider);
            }
        }
        public ActionResult SlideEkle()
        {
            return View();
        }
        public ActionResult SlideDuzenle(int SlideID)
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                var _slideDuzenle = context.Slider.Where(x => x.ID == SlideID).FirstOrDefault();
                return View(_slideDuzenle);
            }
        }
        public ActionResult SlideSil(int SlideID)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    context.Slider.Remove(context.Slider.First(d => d.ID == SlideID));
                    context.SaveChanges();
                    return RedirectToAction("Slider", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Silerken hata oluştu", ex.InnerException);
            }
        }
        [HttpPost]
        public ActionResult SlideEkle(Slider s, HttpPostedFileBase file)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    Slider _slide = new Slider();
                    if (file != null && file.ContentLength > 0)
                    {
                        MemoryStream memoryStream = file.InputStream as MemoryStream;
                        if (memoryStream == null)
                        {
                            memoryStream = new MemoryStream();
                            file.InputStream.CopyTo(memoryStream);
                        }
                        _slide.SliderFoto = memoryStream.ToArray();
                    }
                    _slide.SliderText = s.SliderText;
                    _slide.BaslangicTarih = s.BaslangicTarih;
                    _slide.BitisTarih = s.BitisTarih;
                    context.Slider.Add(_slide);
                    context.SaveChanges();
                    return RedirectToAction("Slider", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Eklerken hata oluştu");
            }
        }
        [HttpPost]
        public ActionResult SlideDuzenle(Slider slide, HttpPostedFileBase file)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    var _slideDuzenle = context.Slider.Where(x => x.ID == slide.ID).FirstOrDefault();
                    if (file != null && file.ContentLength > 0)
                    {
                        MemoryStream memoryStream = file.InputStream as MemoryStream;
                        if (memoryStream == null)
                        {
                            memoryStream = new MemoryStream();
                            file.InputStream.CopyTo(memoryStream);
                        }
                        _slideDuzenle.SliderFoto = memoryStream.ToArray();
                    }
                    _slideDuzenle.SliderText = slide.SliderText;
                    _slideDuzenle.BaslangicTarih = slide.BaslangicTarih;
                    _slideDuzenle.BitisTarih = slide.BitisTarih;
                    context.SaveChanges();
                    return RedirectToAction("Slider", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Güncellerken hata oluştu " + ex.Message);
            }

        }

        #endregion
        #region // Blog

        public ActionResult Blog()
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                var blog = context.Blog.ToList();
                return View(blog);
            }
        }
        public ActionResult BlogEkle()
        {
            return View();
        }
        public ActionResult BlogDuzenle(int BlogID)
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                var _blogDuzenle = context.Blog.Where(x => x.ID == BlogID).FirstOrDefault();
                return View(_blogDuzenle);
            }
        }
        public ActionResult BlogSil(int BlogID)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    context.Blog.Remove(context.Blog.First(d => d.ID == BlogID));
                    context.SaveChanges();
                    return RedirectToAction("Blog", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Silerken hata oluştu", ex.InnerException);
            }
        }
        [HttpPost]
        public ActionResult BlogEkle(Blog b, HttpPostedFileBase file)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    Blog _blog = new Blog();
                    if (file != null && file.ContentLength > 0)
                    {
                        MemoryStream memoryStream = file.InputStream as MemoryStream;
                        if (memoryStream == null)
                        {
                            memoryStream = new MemoryStream();
                            file.InputStream.CopyTo(memoryStream);
                        }
                        _blog.BlogFoto = memoryStream.ToArray();
                    }
                    _blog.BlogBaslik = b.BlogBaslik;
                    _blog.BlogIcerik = b.BlogIcerik;
                    _blog.Tarih = DateTime.Now;
                    context.Blog.Add(_blog);
                    context.SaveChanges();
                    return RedirectToAction("Blog", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Eklerken hata oluştu");
            }
        }
        [HttpPost]
        public ActionResult BlogDuzenle(Blog b, HttpPostedFileBase file)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    var _blogDuzenle = context.Blog.Where(x => x.ID == b.ID).FirstOrDefault();
                    if (file != null && file.ContentLength > 0)
                    {
                        MemoryStream memoryStream = file.InputStream as MemoryStream;
                        if (memoryStream == null)
                        {
                            memoryStream = new MemoryStream();
                            file.InputStream.CopyTo(memoryStream);
                        }
                        _blogDuzenle.BlogFoto = memoryStream.ToArray();
                    }
                    _blogDuzenle.BlogBaslik = b.BlogBaslik;
                    _blogDuzenle.BlogIcerik = b.BlogIcerik;
                    _blogDuzenle.Tarih = DateTime.Now;
                    context.SaveChanges();
                    return RedirectToAction("Blog", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Güncellerken hata oluştu " + ex.Message);
            }

        }

        #endregion
        #region // Personel

        public ActionResult Personel()
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                var personel = context.Takim.ToList();
                return View(personel);
            }
        }
        public ActionResult PersonelEkle()
        {
            return View();
        }
        public ActionResult PersonelDuzenle(int PersonelID)
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                var _personelDuzenle = context.Takim.Where(x => x.ID == PersonelID).FirstOrDefault();
                return View(_personelDuzenle);
            }
        }
        public ActionResult PersonelSil(int PersonelID)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    context.Takim.Remove(context.Takim.First(d => d.ID == PersonelID));
                    context.SaveChanges();
                    return RedirectToAction("Personel", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Silerken hata oluştu", ex.InnerException);
            }
        }
        [HttpPost]
        public ActionResult PersonelEkle(Takim t, HttpPostedFileBase file)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    Takim _personel = new Takim();
                    if (file != null && file.ContentLength > 0)
                    {
                        MemoryStream memoryStream = file.InputStream as MemoryStream;
                        if (memoryStream == null)
                        {
                            memoryStream = new MemoryStream();
                            file.InputStream.CopyTo(memoryStream);
                        }
                        _personel.Foto = memoryStream.ToArray();
                    }
                    _personel.AdSoyad = t.AdSoyad;
                    _personel.Icerik = t.Icerik;
                    _personel.Tip = t.Tip;
                    context.Takim.Add(_personel);
                    context.SaveChanges();
                    return RedirectToAction("Personel", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Eklerken hata oluştu");
            }
        }
        [HttpPost]
        public ActionResult PersonelDuzenle(Takim t, HttpPostedFileBase file)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    var _personelDuzenle = context.Takim.Where(x => x.ID == t.ID).FirstOrDefault();
                    if (file != null && file.ContentLength > 0)
                    {
                        MemoryStream memoryStream = file.InputStream as MemoryStream;
                        if (memoryStream == null)
                        {
                            memoryStream = new MemoryStream();
                            file.InputStream.CopyTo(memoryStream);
                        }
                        _personelDuzenle.Foto = memoryStream.ToArray();
                    }
                    _personelDuzenle.AdSoyad = t.AdSoyad;
                    _personelDuzenle.Icerik = t.Icerik;
                    _personelDuzenle.Tip = t.Tip;
                    context.SaveChanges();
                    return RedirectToAction("Personel", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Güncellerken hata oluştu " + ex.Message);
            }

        }

        #endregion
        #region // Modüller

        public ActionResult Moduller()
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                var moduller = context.Modul.ToList();
                return View(moduller);
            }
        }
        public ActionResult ModulEkle()
        {
            return View();
        }
        public ActionResult ModulDuzenle(int ModulID)
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                var _modulDuzenle = context.Modul.Where(x => x.ID == ModulID).FirstOrDefault();
                return View(_modulDuzenle);
            }
        }
        public ActionResult ModulSil(int ModulID)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    context.Modul.Remove(context.Modul.First(d => d.ID == ModulID));
                    context.SaveChanges();
                    return RedirectToAction("Moduller", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Silerken hata oluştu", ex.InnerException);
            }
        }
        [HttpPost]
        public ActionResult ModulEkle(Modul m, HttpPostedFileBase file)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    Modul _modul = new Modul();
                    if (file != null && file.ContentLength > 0)
                    {
                        MemoryStream memoryStream = file.InputStream as MemoryStream;
                        if (memoryStream == null)
                        {
                            memoryStream = new MemoryStream();
                            file.InputStream.CopyTo(memoryStream);
                        }
                        _modul.ModulFoto = memoryStream.ToArray();
                    }
                    _modul.ModulBaslik = m.ModulBaslik;
                    _modul.ModulIcerik = m.ModulIcerik;
                    _modul.Tarih = DateTime.Now;
                    context.Modul.Add(_modul);
                    context.SaveChanges();
                    return RedirectToAction("Moduller", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Eklerken hata oluştu");
            }
        }
        [HttpPost]
        public ActionResult ModulDuzenle(Modul m, HttpPostedFileBase file)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    var _modulDuzenle = context.Modul.Where(x => x.ID == m.ID).FirstOrDefault();
                    if (file != null && file.ContentLength > 0)
                    {
                        MemoryStream memoryStream = file.InputStream as MemoryStream;
                        if (memoryStream == null)
                        {
                            memoryStream = new MemoryStream();
                            file.InputStream.CopyTo(memoryStream);
                        }
                        _modulDuzenle.ModulFoto = memoryStream.ToArray();
                    }
                    _modulDuzenle.ModulBaslik = m.ModulBaslik;
                    _modulDuzenle.ModulIcerik = m.ModulIcerik;
                    _modulDuzenle.Tarih = DateTime.Now;
                    context.SaveChanges();
                    return RedirectToAction("Moduller", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Güncellerken hata oluştu " + ex.Message);
            }

        }

        #endregion
        #region // Duyurular

        public ActionResult Duyurular()
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                var duyurular = context.Duyuru.ToList();
                return View(duyurular);
            }
        }
        public ActionResult DuyuruEkle()
        {
            return View();
        }
        public ActionResult DuyuruDuzenle(int DuyuruID)
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                var _duyuruDuzenle = context.Duyuru.Where(x => x.ID == DuyuruID).FirstOrDefault();
                return View(_duyuruDuzenle);
            }
        }
        public ActionResult DuyuruSil(int DuyuruID)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    context.Duyuru.Remove(context.Duyuru.First(d => d.ID == DuyuruID));
                    context.SaveChanges();
                    return RedirectToAction("Duyurular", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Silerken hata oluştu", ex.InnerException);
            }
        }
        [HttpPost]
        public ActionResult DuyuruEkle(Duyuru d, HttpPostedFileBase file)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    Duyuru _duyuru = new Duyuru();
                    if (file != null && file.ContentLength > 0)
                    {
                        MemoryStream memoryStream = file.InputStream as MemoryStream;
                        if (memoryStream == null)
                        {
                            memoryStream = new MemoryStream();
                            file.InputStream.CopyTo(memoryStream);
                        }
                        _duyuru.DuyuruFoto = memoryStream.ToArray();
                    }
                    _duyuru.DuyuruBaslik = d.DuyuruBaslik;
                    _duyuru.DuyuruIcerik = d.DuyuruIcerik;
                    _duyuru.Tarih = DateTime.Now;
                    context.Duyuru.Add(_duyuru);
                    context.SaveChanges();
                    return RedirectToAction("Duyurular", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Eklerken hata oluştu");
            }
        }
        [HttpPost]
        public ActionResult DuyuruDuzenle(Duyuru d, HttpPostedFileBase file)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    var _duyuruDuzenle = context.Duyuru.Where(x => x.ID == d.ID).FirstOrDefault();
                    if (file != null && file.ContentLength > 0)
                    {
                        MemoryStream memoryStream = file.InputStream as MemoryStream;
                        if (memoryStream == null)
                        {
                            memoryStream = new MemoryStream();
                            file.InputStream.CopyTo(memoryStream);
                        }
                        _duyuruDuzenle.DuyuruFoto = memoryStream.ToArray();
                    }
                    _duyuruDuzenle.DuyuruBaslik = d.DuyuruBaslik;
                    _duyuruDuzenle.DuyuruIcerik = d.DuyuruIcerik;
                    _duyuruDuzenle.Tarih = DateTime.Now;
                    context.SaveChanges();
                    return RedirectToAction("Duyurular", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Güncellerken hata oluştu " + ex.Message);
            }

        }

        #endregion
        #region // Referanslar

        public ActionResult Referanslar()
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                var referanslar = context.Referans.ToList();
                return View(referanslar);
            }
        }
        public ActionResult ReferansEkle()
        {
            return View();
        }
        public ActionResult ReferansDuzenle(int ReferansID)
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                var _referansDuzenle = context.Referans.Where(x => x.ID == ReferansID).FirstOrDefault();
                return View(_referansDuzenle);
            }
        }
        public ActionResult ReferansSil(int ReferansID)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    context.Referans.Remove(context.Referans.First(d => d.ID == ReferansID));
                    context.SaveChanges();
                    return RedirectToAction("Referanslar", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Silerken hata oluştu", ex.InnerException);
            }
        }
        [HttpPost]
        public ActionResult ReferansEkle(Referans r, HttpPostedFileBase file)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    Referans _referans = new Referans();
                    if (file != null && file.ContentLength > 0)
                    {
                        MemoryStream memoryStream = file.InputStream as MemoryStream;
                        if (memoryStream == null)
                        {
                            memoryStream = new MemoryStream();
                            file.InputStream.CopyTo(memoryStream);
                        }
                        _referans.ReferansFoto = memoryStream.ToArray();
                    }
                    _referans.ReferansBaslik = r.ReferansBaslik;
                    _referans.ReferansIcerik = r.ReferansIcerik;
                    _referans.Tarih = DateTime.Now;
                    context.Referans.Add(_referans);
                    context.SaveChanges();
                    return RedirectToAction("Referanslar", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Eklerken hata oluştu");
            }
        }
        [HttpPost]
        public ActionResult ReferansDuzenle(Referans r, HttpPostedFileBase file)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    var _referansDuzenle = context.Referans.Where(x => x.ID == r.ID).FirstOrDefault();
                    if (file != null && file.ContentLength > 0)
                    {
                        MemoryStream memoryStream = file.InputStream as MemoryStream;
                        if (memoryStream == null)
                        {
                            memoryStream = new MemoryStream();
                            file.InputStream.CopyTo(memoryStream);
                        }
                        _referansDuzenle.ReferansFoto = memoryStream.ToArray();
                    }
                    _referansDuzenle.ReferansBaslik = r.ReferansBaslik;
                    _referansDuzenle.ReferansIcerik = r.ReferansIcerik;
                    _referansDuzenle.Tarih = DateTime.Now;
                    context.SaveChanges();
                    return RedirectToAction("Referanslar", "Admin");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Güncellerken hata oluştu " + ex.Message);
            }

        }

        #endregion
    }
}